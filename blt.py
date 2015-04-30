import json
import os
import subprocess
import sys
from mako.template import Template
from random import randint

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
#        failures = klee_get_failures()
#        replay(failures)

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

    replay = 0
    trace = []
    output_tmpl = Template(filename=(os.path.join(env['blt'], 'templates', 'output.mako')))
    failed = open(os.path.abspath(os.path.join(tmpdir, 'failure.out')), 'r')
    lines = failed.read().splitlines()
    for line in lines:
        if line == "#####":
            output_str = output_tmpl.render(
                    headers=[os.path.abspath(os.path.join(jfile_dir, h)) for h in data['header_files']],
                    funcs=data['funcs'], class1=data['class1'], class2=data['class2'], trace=trace)
            output = open(os.path.join(tmpdir, 'replay{0}.cpp'.format(replay)), 'w')
            output.write(output_str)
            output.close()
            trace = []
            replay += 1
        else:
            line = line.split(',')
            trace.append((int(line[0]), line[1:]))

if __name__ == '__main__':
    main()

