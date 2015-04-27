import json
import os
import subprocess
import sys
from mako.template import Template

if __name__ == '__main__':
    # Check environment and argument
    if 'BLT' not in os.environ:
        sys.stderr.write('Need to set BLT environment variable to directory of BLT\n')
        exit(1)
    blt = os.environ['BLT']

    if 'LLVMGCC' not in os.environ:
        sys.stderr.write('Need to set LLVMGCC environment variable to directory of llvm-g++ binary\n')
        exit(1)
    llvmgcc = os.environ['LLVMGCC']

    if 'LLVM29' not in os.environ:
        sys.stderr.write('Need to set LLVM29 environment variable to directory of llvm-link binary for llvm 2.9\n')
        exit(1)
    llvm29 = os.environ['LLVM29']

    if 'KLEE' not in os.environ:
        sys.stderr.write('Need to set KLEE environment variable to directory of KLEE\n')
        exit(1)
    klee_include = os.path.join(os.environ['KLEE'], 'include')

    if (len(sys.argv) < 2):
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


    traces_tmpl = Template(
            filename=(os.path.join(blt, 'templates', 'traces.mako')))
    traces_str = traces_tmpl.render(traces=data['traces'], class1=data['class1'],
            class2=data['class2'])

    body_tmpl = Template(filename=(os.path.join(blt, 'templates', 'body.mako')))
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

    # Compile the source files to LLVM bytecode
    llvmgcc_bin = os.path.join(llvmgcc,'llvm-g++')
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
            llvmgcc_bin, klee_include, harness_out, os.path.join(tmpdir, 'harness.cpp'))
    if subprocess.call(cmd.split()) != 0:
        exit(1)
    bc_files.append(harness_out)
    harness_bc = os.path.join(tmpdir, 'harness.bc')
    llvmlink_bin = os.path.join(llvm29, 'llvm-link')
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

        output_tmpl = Template(filename=(os.path.join(blt, 'templates', 'body.mako')))
        output_str = output_tmpl.render(
                headers=[os.path.join(jfile_dir, h) for h in data['header_files']],
                funcs_str=funcs_str, traces_str=traces_str,
                ntraces=(len(data['traces'])))
        output = open(os.path.join(tmpdir, 'trace{0}_out.cpp'.format(i)), 'w')
        output.write(output_str)
        output.close()
