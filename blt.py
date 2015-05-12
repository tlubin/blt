import json
import argparse
import glob
import subprocess
import os
import sys
import copy
import time
import random
from mako.template import Template

env = {}
args = {}
data = {}
jfile_dir = ''
tmpdir = ''
SEED = random.randint(1, 1000)
default_trace_len = 50
default_sym_len = 2

# globals for generation of default traces
num_traces = 10
swarm1_length = 500
swarm2_length = 50
timeout = 60

# Colors for colorful output to console
GREEN = '\033[1m\033[32m'
RED = '\033[1m\033[31m'
MAGENTA = '\033[1m\033[35m'
RESET = '\033[0m'

# Check environment variables
def check_env():
    global env
    if 'BLT' not in os.environ:
        sys.stderr.write('Need to set BLT environment variable to directory of BLT\n')
        exit(1)
    env['blt'] = os.environ['BLT']

    if 'LLVMGCC' not in os.environ:
        sys.stderr.write('Need to set LLVMGCC environment variable to directory of llvm-g++ binary\n')
        exit(1)
    env['llvmgcc'] = os.environ['LLVMGCC']

    if 'LLVM29' not in os.environ:
        sys.stderr.write('Need to set LLVM29 environment variable to directory of llvm-link binary for llvm 2.9\n')
        exit(1)
    env['llvm29'] = os.environ['LLVM29']

    if 'KLEE' not in os.environ:
        sys.stderr.write('Need to set KLEE environment variable to directory of KLEE\n')
        exit(1)
    env['klee_include'] = os.path.join(os.environ['KLEE'], 'include')
    return env

def get_args():
    global args
    parser = argparse.ArgumentParser()
    parser.add_argument('jfile', help='JSON file')
    g = parser.add_mutually_exclusive_group(required=True)
    g.add_argument('--trace', action='store_true', help='Run trace')
    g.add_argument('--replay', dest='rfile', help='Run replay, provide replay file to replay')
    g.add_argument('--replay-all', dest='rdir', help='Run all replays, provide replay directory to replay')
    g.add_argument('--mutants-concolic', action='store_true', help='Evaluate default traces on mutants using concolic approach')
    g.add_argument('--mutants-concrete', action='store_true', help='Evaluate default traces on mutants using concrete approach')
    args = parser.parse_args()

# Create harness from JSON data
def write_harness(num=0):
    global tmpdir
    function_tmpl = Template(
            filename=(os.path.join(env['blt'], 'templates', 'functions.mako')))
    funcs_str = function_tmpl.render(funcs=data['funcs'], class1=data['class1'],
            class2=data['class2'])

    traces_tmpl = Template(
            filename=(os.path.join(env['blt'], 'templates', 'traces.mako')))
    traces_str = traces_tmpl.render(funcs=data['funcs'], traces=data['traces'], class1=data['class1'],
            class2=data['class2'])

    body_tmpl = Template(filename=(os.path.join(env['blt'], 'templates', 'body.mako')))
    body_str = body_tmpl.render(
            headers=[os.path.abspath(os.path.join(jfile_dir, h)) for h in data['header_files']],
            funcs_str=funcs_str, traces_str=traces_str,
            ntraces=(len(data['traces'])),
            seed=SEED)

    tmpdir = os.path.join(jfile_dir, 'blt_tmp_{0}'.format(num))
    if os.path.exists(tmpdir):
        subprocess.call('rm -rf {0}'.format(tmpdir).split())
    os.mkdir(tmpdir)
    harness = open(os.path.join(tmpdir, 'harness.cpp'), 'w')
    harness.write(body_str)
    harness.close()

# Search KLEE output directory to find failing test cases. Returns a list in
# which each element (i.e. each failing test case) is a list of dictionaries,
# each of which has the keys 'name', 'size' and 'data' and represents the
# concrete value assigned by KLEE to a particular symbolic value.
def klee_get_failures(klee_output_dir):
    # Identify failed test runs by files with .err extension, omitting
    # .user.err files.
    failed_klee_runs = []
    for outf in os.listdir(klee_output_dir):
        if not outf.endswith('.err') or outf.endswith('.user.err'):
            continue
        # Parse each corresponding ktest file.
        ktest_file = os.path.join(klee_output_dir, outf.split('.')[0] + '.ktest')
        cmd = "ktest-tool --write-ints %s | tail -n+4 | awk '{print $4}'"
        try:
            lines = subprocess.check_output(cmd % ktest_file,
                    shell=True).split()
        except CalledProcessError:
            print "Failure parsing KLEE output."
            exit(1)
        assert len(lines) % 3 == 0
        failed_run = []
        i = 0
        while i < len(lines):
           val = {}
           val['name'] = lines[i][1:-1]
           val['size'] = lines[i+1]
           val['data'] = lines[i+2]
           i += 3
           failed_run.append(val)
        failed_klee_runs.append(failed_run)
    return failed_klee_runs

def run_replay(replay_file, verbose=1):
    sources = " "
    for source_file in data['source_files']:
        sources += os.path.abspath(os.path.join(jfile_dir, source_file)) + ' '
    cmd = 'g++ -o {0} {1} {2}'.format(replay_file.replace('.cpp',''), replay_file, sources)
    devnull = open('/dev/null', 'w')
    stderr = None if verbose else devnull
    if subprocess.call(cmd.split(), stderr=stderr) != 0:
        devnull.close()
        return 0
    cmd = '{0}'.format(replay_file.replace('.cpp',''))
    if subprocess.call(cmd.split(), stderr=stderr) != 0:
        devnull.close()
        return 0
    devnull.close()
    return 1


def write_replay(failure, trace, tracenum, failnum):
    sym_calls = [x for x in failure if 'idx' in x['name']]
    sym_args = [x for x in failure if 'arg' in x['name']]
    sym_args = map(lambda x: x['data'], sym_args)
    sym_call_num = 0
    sym_arg_num = 0

    for node in trace:
        if node['symbolic_trace'] == 'true':
            called = min(node['len'], len(sym_calls) - sym_call_num)
            node['len'] = called
            node['calls'] = sym_calls[sym_call_num:sym_call_num+called]
            node['calls'] = map(lambda x: node['funcs'][int(x['data'])], node['calls'])
            sym_call_num += called
        if node['symbolic_args'] == 'true':
            node['args'] = []
            for call in node['calls']:
                func = [func for func in data['funcs'] if func['name']==call][0]
                if sym_arg_num + len(func['args']) > len(sym_args):
                    break
                node['args'] += [sym_args[sym_arg_num:sym_arg_num+len(func['args'])]]
                sym_arg_num += len(func['args'])
            node['len'] = len(node['args'])

    # Generate c++ code that will mirror failing run to get arguments
    getargs_tmpl = Template(
            filename=(os.path.join(env['blt'], 'templates', 'getargs.mako')))
    getargs_str = getargs_tmpl.render(funcs=data['funcs'], trace=trace,
                                      seed=SEED, class1=data['class1'],
                                      class2=data['class2'],
                                      headers=[os.path.abspath(os.path.join(jfile_dir, h)) for h in data['header_files']])
    getargs = open(os.path.join(tmpdir, 'getargs.cpp'), 'w');
    getargs.write(getargs_str)
    getargs.close()

    # Compile and run c++ code and collect arguments from output file
    sources = " "
    for source_file in data['source_files']:
        sources += os.path.abspath(os.path.join(jfile_dir, source_file)) + ' '
    cmd = 'g++ -o {0} {1} {2}'.format(os.path.join(tmpdir, 'getargs'), os.path.join(tmpdir, 'getargs.cpp'), sources)
    subprocess.call(cmd.split())
    run_cmd = os.path.join(tmpdir, 'getargs')
    getargs_ret = os.path.join(tmpdir, 'getargs_ret')

    with open(getargs_ret, 'w') as outfile:
        subprocess.call(run_cmd, stdout=outfile)
    with open(getargs_ret, 'r') as infile:
        calls_args = infile.read().splitlines()

    calls_args = map(lambda x: (x.split(',')[0], x.split(',')[1:]), calls_args)

    # TODO: there is a BUG when the implementations print to stdout because we are parsing stdout
    # FIX: write to another file descriptor (some default or passed in filename)

    output_tmpl = Template(filename=(os.path.join(env['blt'], 'templates', 'output.mako')))
    output_str = output_tmpl.render(
        headers=[os.path.abspath(os.path.join(jfile_dir, h)) for h in data['header_files']],
        funcs=data['funcs'], class1=data['class1'], class2=data['class2'], calls_args=calls_args, seed=SEED)
    replay_file = os.path.join(tmpdir, 'replay{0}_{1}.cpp'.format(tracenum, failnum))
    with open(replay_file, 'w') as replay_fd:
        replay_fd.write(output_str)

    # Run the replay file to make sure it fails
    success = run_replay(replay_file, verbose=0)
    if success:
        print MAGENTA + 'HMM: replay worked?' + RESET
    else:
        print RED + 'BLT: ERROR: {0}'.format(replay_file) + RESET

# Return 1 on finding a mutant, -k on timeout for k traces and 0 otherwise
def compile_and_run_klee(exitearly=0, verbose=1):
    # Compile the source files to LLVM bytecode
    llvmgcc_bin = os.path.join(env['llvmgcc'],'llvm-g++')
    bc_files = []
    for i,src in enumerate(data['source_files']):
        out = os.path.join(tmpdir, 'out{0}.bc'.format(i))
        cmd = '{0} -c -g -emit-llvm -o {1} {2}'.format(
                llvmgcc_bin, out, os.path.abspath(os.path.join(jfile_dir, src)))
        if subprocess.call(cmd.split()) != 0:
            exit(1)
        bc_files.append(out)

    # Compile harness and link bytecode files to it
    harness_out = os.path.join(tmpdir, 'out{0}.bc'.format(len(data['source_files'])))
    cmd = '{0} -c -g -emit-llvm -I {1} -o {2} {3}'.format(
            llvmgcc_bin, env['klee_include'], harness_out, os.path.join(tmpdir, 'harness.cpp'))
    if subprocess.call(cmd.split()) != 0:
        exit(1)
    bc_files.append(harness_out)
    harness_bc = os.path.join(tmpdir, 'harness.bc')
    llvmlink_bin = os.path.join(env['llvm29'], 'llvm-link')
    cmd = '{0} -o {1} {2}'.format(
        llvmlink_bin, harness_bc,' '.join(bc_files))
    if subprocess.call(cmd.split()) != 0:
        exit(1)

    # Call KLEE
    timeouts = 0
    for i in range(len(data['traces'])):
        klee_output_dir = os.path.join(tmpdir, 'klee{0}'.format(i))
        klee_print_file = os.path.join(tmpdir, 'klee_output.txt')
        if verbose:
            print MAGENTA + '\nBLT: running trace {0}\n'.format(i) + RESET

        global start
        t0 = time.time()
#        cmd = 'klee -emit-all-errors -max-time={3} -output-dir={0} {1} {2}'.format(
#            klee_output_dir, harness_bc, i, start + timeout - t0)

        cmd = 'klee -exit-on-error -emit-all-errors -max-time={3} -output-dir={0} {1} {2}'.format(
            klee_output_dir, harness_bc, i, timeout)

        # time the klee process
        with open(klee_print_file, 'w') as klee_print_fd:
            ret = subprocess.call(cmd.split(), stderr=klee_print_fd)

        # get number of paths
        with open(klee_print_file, 'r') as klee_print_fd:
            lines = klee_print_fd.readlines()
            # if ret == 1 either halt timer or klee found an error and exited on failure
            if ret == 1:
                haltline = [x for x in lines if 'HaltTimer' in x]
                if len(haltline) > 0:
                    timeouts += 1
                    continue
                return 1
            line = lines[-2].split()
            num_paths = line[-1]
        time_found = time.time() - start

        failures = klee_get_failures(klee_output_dir)
        if len(failures) == 0:
            if verbose:
                print GREEN + 'BLT: trace {0} completed successfully'.format(i) + RESET
        for n, f in enumerate(failures):
         #   write_replay(f, copy.deepcopy(data['traces'][i]), i, n)
            if verbose:
                print RED + 'BLT: ERROR' + RESET

        if len(failures) > 0 and exitearly:
            return 1
    if timeouts > 0:
        return -1 * timeouts
    return 0

# Generate a swarm of concolic traces from the powerset of the set of all
# functions.  The length of each trace is actually default_trace_len + 2.
def generate_default_traces():
    powerset = [[]]
    for f in data['funcs']:
        powerset.extend([x + [f['name']] for x in powerset])
    data['traces'] = []
    return_funcs = [x['name'] for x in data['funcs'] if x['return'] != 'void']
    powerset.remove([])
    for _ in range(num_traces):
        sym = { 'funcs' : return_funcs, 'len' : 1,
                'symbolic_args' : 'true', 'symbolic_trace' : 'true' }
        swarm1 = random.choice(powerset)
        con1 = { 'funcs' : swarm1, 'len' : swarm1_length,
                 'symbolic_args' : 'false', 'symbolic_trace' : 'false' }
        swarm2 = random.choice(powerset)
        con2 = { 'funcs' : swarm2, 'len' : swarm2_length,
                 'symbolic_args' : 'false', 'symbolic_trace' : 'false' }
        data['traces'].append([con1, sym, con2])

def generate_concrete_traces():
    powerset = [[]]
    for f in data['funcs']:
        powerset.extend([x + [f['name']] for x in powerset])
    data['traces'] = []
    return_funcs = [x['name'] for x in data['funcs'] if x['return'] != 'void']
    powerset.remove([])
    for _ in range(num_traces):
        swarm1 = random.choice(powerset)
        con1 = { 'funcs' : swarm1, 'len' : swarm1_length,
                 'symbolic_args' : 'false', 'symbolic_trace' : 'false' }
        swarm2 = random.choice(powerset)
        con2 = { 'funcs' : swarm2, 'len' : swarm2_length,
                 'symbolic_args' : 'false', 'symbolic_trace' : 'false' }
        data['traces'].append([con1, con2])

# Given a string describing a C type, return a string representing a random
# value of that type.
def gen_arg(typ):
    if typ == 'int':
        return random.choice(['INT_MAX', 'INT_MIN', '0',
                str(random.randint(0,50)), str(-random.randint(0,50))])
    else:
        assert False

# Given the name of a function, update `concrete_args` with random args for
# one call to that function.
def update_concrete_args(func_name, concrete_args):
    f = next(f for f in data['funcs'] if f['name'] == func_name)
    for arg in f['args']:
        if arg not in concrete_args:
            concrete_args[arg] = [gen_arg(arg)]
        else:
            concrete_args[arg].append(gen_arg(arg))

# Given a dictionary of concrete values indexed by C type, inject values into
# template of C++ argument generators.
def inject_concrete_args(concrete_args):
    arg_tmpl = Template(filename=(os.path.join(env['blt'], 'templates',
        'blt_args.mako')))
    arg_str = arg_tmpl.render(blt_dir=env['blt'], concrete_args=concrete_args)
    # TODO: write to a file in `tmpdir` instead of BLT directory
    blt_args = os.path.join(env['blt'], 'blt_args.cpp')
    with open(blt_args, 'w') as f:
        f.write(arg_str)

# Return 1 on finding a mutant and 0 otherwise
def run_traces(exitearly=0, verbose=1, num=0):
    concrete_args = {}
    for trace in data['traces']:
        for node in trace:
            if node['symbolic_trace'] == 'false':
                calls = []
                nfuncs = len(node['funcs'])
                for i in range(node['len']):
                    calls.append(node['funcs'][random.randint(0,nfuncs-1)])
                    update_concrete_args(calls[-1], concrete_args)
                node['calls'] = calls
            else:  # symbolic_trace == true
                for i in range(node['len']):
                    for func in node['funcs']:
                        update_concrete_args(func, concrete_args)

    inject_concrete_args(concrete_args)
    write_harness(num)
    return compile_and_run_klee(exitearly, verbose)

def run_mutants(mutants):
    totalfound = 0
    times = []
    timeouts = 0
    print("TIMEOUT: {0}".format(timeout))
    for i in mutants:
        sys.stderr.write('CHECKPOINT: {0} of {1}\n'.format(totalfound, i - mutants[0]))
        data['source_files'] += [os.path.join('mutations', 'rbtree{0}.cpp'.format(i))]
        t0 = time.time()
        found = run_traces(exitearly=1, verbose=0, num=0)
        t1 = time.time()
        if found < 0:
            timeouts += -1*found
            print "{0}: timed out on {1} of {2} traces".format(i, -1*found, num_traces)
        elif found == 1:
            totalfound += 1
            t = t1-t0
            times.append(t)
            print "{0}: found mutant in {1}".format(i, t)
        else:
            print "{0}: didn't find mutant".format(i)
        data['source_files'].pop()
    print "{0} of {1} FOUND with average {2}".format(totalfound, len(mutants), sum(times) / totalfound)
    print "{0} timeouts".format(timeouts)


def main():
    global data, jfile_dir
    check_env()
    get_args()

    jfile_dir = os.path.dirname(args.jfile)
    with open(args.jfile) as json_file:
        data = json.load(json_file)

    data['header_files'] += [os.path.join(env['blt'], 'blt_args.hpp')]
    data['source_files'] += [os.path.join(env['blt'], 'blt_args.cpp')]

    def do_run_replay(replay):
        success = run_replay(replay, verbose=1)
        if success:
            print GREEN + "BLT: {0} succeeded".format(replay) + RESET
        else:
            print RED + "BLT: {0} failed".format(replay) + RESET

    # run the user traces if specified, else default traces
    if args.trace:
        if 'traces' not in data:
            generate_default_traces()
        run_traces(exitearly=1)

    # replay the requested file
    elif args.rfile:
        do_run_replay(args.rfile)

    # replay all files in the given directory
    elif args.rdir:
        replays = glob.glob(os.path.join(args.rdir, 'replay*.cpp'))
        for replay in sorted(replays):
            do_run_replay(replay)

    # run either concolic or concrete traces for evaluating mutant detection
    elif args.mutants_concolic:
        generate_default_traces()
        run_mutants(range(500, 600))
    elif args.mutants_concrete:
        generate_concrete_traces()
        run_mutants(range(150,160))


if __name__ == '__main__':
    main()

