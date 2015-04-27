import json
import os
import subprocess
import sys
from mako.template import Template

### Just for testing purposes...

traces = \
[
    [
        { 'symbolic_trace' : 'false', 'symbolic_args' : 'false', 'len' : 20, 'funcs' : ['insert'] },
        { 'symbolic_trace' : 'true', 'symbolic_args' : 'true', 'len' : 2, 'funcs' : ['member', 'get_size', 'insert', 'remove'] }
    ],
    [
        { 'symbolic_trace' : 'false', 'symbolic_args' : 'false', 'len' : 20, 'funcs' : ['insert', 'get_size'] }
    ]
]

### traces testing calcs
'''
traces = \
[
    [
        { 'symbolic_trace' : 'false', 'symbolic_args' : 'false', 'len' : 1, 'funcs' : ['init_pressed'] },
        { 'symbolic_trace' : 'false', 'symbolic_args' : 'false', 'len' : 200, 'funcs' : ['zero_pressed', 'one_pressed', 'plus_pressed', 'mult_pressed'] },
        { 'symbolic_trace' : 'true', 'symbolic_args' : 'true', 'len' : 2, 'funcs' : ['zero_pressed', 'one_pressed', 'plus_pressed', 'mult_pressed'] },
        { 'symbolic_trace' : 'false', 'symbolic_args' : 'false', 'len' : 1, 'funcs' : ['eval_pressed'] }
    ]
]
'''
###

if __name__ == '__main__':
    # Check environment and argument
    if 'BLT' not in os.environ:
        sys.stderr.write('Need to set BLT environment variable to directory of BLT\n')
        exit(1)
    blt = os.environ['BLT']

    if 'KLEE' not in os.environ:
        sys.stderr.write('Need to set KLEE environment variable to directory of KLEE\n')
        exit(1)
    klee_include = os.path.join(os.environ['KLEE'], 'include')

    if (not sys.argv[1]):
        sys.stderr.write('Please pass in JSON file\n')
        exit(1)
    jfile = sys.argv[1]
    jfile_dir = os.path.dirname(jfile)
    with open(jfile) as json_file:
        data = json.load(json_file)

    # Create harness from JSON data
    function_tmpl = Template(
            filename=(os.path.join(blt, 'templates', 'functions.mako')))
    funcs_str = function_tmpl.render(funcs=data['funcs'], class1=data['class1'],
            class2=data['class2'])

    # TODO: just a placeholder
    data['traces'] = traces

    traces_tmpl = Template(
            filename=(os.path.join(blt, 'templates', 'traces.mako')))
    traces_str = traces_tmpl.render(traces=data['traces'], class1=data['class1'],
            class2=data['class2'])

    body_tmpl = Template(filename=(os.path.join(blt, 'templates', 'body.mako')))
    body_str = body_tmpl.render(headers=data['header_files'],
            funcs_str=funcs_str, traces_str=traces_str,
            ntraces=(len(data['traces'])))

    tmpdir = os.path.join(blt, 'tmp')
    if os.path.exists(tmpdir):
        subprocess.call('rm -rf {0}'.format(tmpdir).split())
    os.mkdir(tmpdir)
    harness = open(os.path.join(tmpdir, 'harness.cpp'), 'w')
    harness.write(body_str)
    harness.close()
 
    # Compile the source files to LLVM IR
    bc_files = []
    for i,src in enumerate(data['source_files'] +
            [os.path.join(tmpdir, 'harness.cpp')]):
        out = os.path.join(tmpdir, 'out{0}.bc'.format(i))
        cmd = 'llvm-g++ -c -g -emit-llvm -I {0} -o {1} {2}'.format(
                klee_include, out, os.path.join(jfile_dir,src))
        if subprocess.call(cmd.split()) != 0:
            exit(1)
        bc_files.append(out)

    harness_bc = os.path.join(tmpdir, 'harness.bc')
    cmd = 'llvm-link -o {0} '.format(harness_bc) + ' '.join(bc_files)
    if subprocess.call(cmd.split()) != 0:
        exit(1)

    # Call KLEE
    for i in range(len(data['traces'])):
        klee_output_dir = os.path.join(tmpdir, 'klee{0}'.format(i))
        print '\n\nRUNNING TRACE {0}\n'.format(i)
        cmd = 'klee -emit-all-errors -output-dir={0} {1} {2}'.format(
                klee_output_dir, harness_bc, i)
        subprocess.call(cmd.split())
