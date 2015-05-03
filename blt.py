import json
import os
import subprocess
import sys
from mako.template import Template
from random import randint
import re

env = {}
args = {}
data = {}
jfile_dir = ''
tmpdir = ''

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

# Eventually we may have more commandline flags to pass in...
# Use argparse or optparse
def get_args():
    global args
    if (len(sys.argv) < 2):
        sys.stderr.write('Usage: python blt.py foo.json\n')
        exit(1)
    args['jfile'] = sys.argv[1]

# Create harness from JSON data
def write_harness():
    global tmpdir
    function_tmpl = Template(
            filename=(os.path.join(env['blt'], 'templates', 'functions.mako')))
    funcs_str = function_tmpl.render(funcs=data['funcs'], class1=data['class1'],
            class2=data['class2'])

    traces_tmpl = Template(
            filename=(os.path.join(env['blt'], 'templates', 'traces.mako')))
    traces_str = traces_tmpl.render(traces=data['traces'], class1=data['class1'],
            class2=data['class2'])

    body_tmpl = Template(filename=(os.path.join(env['blt'], 'templates', 'body.mako')))
    body_str = body_tmpl.render(
            headers=[os.path.abspath(os.path.join(jfile_dir, h)) for h in data['header_files']],
            funcs_str=funcs_str, traces_str=traces_str,
            ntraces=(len(data['traces'])))

    tmpdir = os.path.join(jfile_dir, 'blt_tmp')
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
    # Identify failed test runs by files with .err extension.
    out_files = os.listdir(klee_output_dir)
    err_file = re.compile('^(test.*)\..*\.err$')
    failed_klee_runs = []
    for outf in out_files:
        m = err_file.match(outf)
        if not m:
            continue
        # Parse each corresponding ktest file.
        ktest_file = os.path.join(klee_output_dir, m.group(1) + ".ktest")
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

# TODO! Deal with filenames and directories better...
def replay(failure, trace, num):
    # TL: for now so we can call replay(None, ...)
    if failure:
        sym_calls = [x for x in failure if 'idx' in x['name']]
        sym_args = [x for x in failure if 'arg' in x['name']]
    else:
        sym_calls = []
        sym_args = []
    calls = []
    args = []
    sym_call_num = 0
    sym_arg_num = 0
    conc_call_num = 0

    # Generate c++ code that will mirror failing run to get arguments
    getargs_tmpl = Template(
            filename=(os.path.join(env['blt'], 'templates', 'getargs.mako')))
    getargs_str = getargs_tmpl.render(funcs=data['funcs'], trace=trace, sym_calls=sym_calls)
    getargs = open(os.path.join(tmpdir, 'getargs.cpp'), 'w')
    getargs.write(getargs_str)
    getargs.close()

    # Compile and run c++ code and collect arguments from output file
    llvmgcc_bin = os.path.join(env['llvmgcc'],'llvm-g++')
    compile_cmd = '{0} -o {1} {2}'.format(llvmgcc_bin, os.path.join(tmpdir, 'getargs'), os.path.join(tmpdir, 'getargs.cpp'))
    subprocess.call(compile_cmd.split())
    run_cmd = os.path.join(tmpdir, 'getargs')
    getargs_ret = os.path.join(tmpdir, 'getargs_ret')
    with open(getargs_ret, 'w') as outfile:
        subprocess.call(run_cmd, stdout=outfile)
    with open(getargs_ret, 'r') as infile:
        concrete_args = infile.read().splitlines()

    for node in trace:
        if node['symbolic_trace'] == 'true':
            for i in range(node['len']):
                info = sym_calls[sym_call_num]
                calls.append(node['funcs'][int(info['data'])])
                sym_call_num += 1
        else:
            calls += node['calls']
        if node['symbolic_args'] == 'true':
            funcs = calls[-node['len']:]
            for i in range(node['len']):
                f = [f for f in data['funcs'] if f['name'] == funcs[i]][0]
                f_args = []
                for _ in range(len(f['args'])):
                    f_args.append(sym_args[sym_arg_num]['data'])
                    sym_arg_num += 1
                args.append(f_args)
        else:
            for i in range(node['len']):
                args.append(concrete_args[conc_call_num].split(',')[1:])
                conc_call_num += 1

    output_tmpl = Template(filename=(os.path.join(env['blt'], 'templates', 'output.mako')))
    output_str = output_tmpl.render(
        headers=[os.path.abspath(os.path.join(jfile_dir, h)) for h in data['header_files']],
        funcs=data['funcs'], class1=data['class1'], class2=data['class2'], calls_args=zip(calls,args))
    output = open(os.path.join(tmpdir, 'replay{0}.cpp'.format(num)), 'w')
    output.write(output_str)
    output.close()

def compile_and_run_klee():
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
    for i in range(len(data['traces'])):
        klee_output_dir = os.path.join(tmpdir, 'klee{0}'.format(i))
        print '\n\nRUNNING TRACE {0}\n'.format(i)
        cmd = 'klee -emit-all-errors -output-dir={0} {1} {2}'.format(
                klee_output_dir, harness_bc, i)
        subprocess.call(cmd.split())
        failures = klee_get_failures(klee_output_dir)
        # TL: for now
        if len(failures == 0):
            replay(None, data['traces'][i], 0)
        # TL: end for now
        for n, f in enumerate(failures):
            replay(f, data['traces'][i], n)

def main():
    global data, jfile_dir
    check_env()
    get_args()

    jfile_dir = os.path.dirname(args['jfile'])
    with open(args['jfile']) as json_file:
        data = json.load(json_file)

    # Add a "calls" field for the actual concrete function calls
    for trace in data['traces']:
        for node in trace:
            if node['symbolic_trace'] == 'false':
                calls = []
                nfuncs = len(node['funcs'])
                for i in range(node['len']):
                    calls.append(node['funcs'][randint(0,nfuncs-1)])
                node['calls'] = calls

    write_harness()
    compile_and_run_klee()

if __name__ == '__main__':
    main()

