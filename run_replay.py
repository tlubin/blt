import json
import sys
import os
import subprocess

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

    if (len(sys.argv) < 2):
        sys.stderr.write('Please pass in replay file\n')
        exit(1)
    rfile = sys.argv[1]
    rfile_dir = os.path.dirname(rfile)
    replay_file = open(rfile)

    if (len(sys.argv) < 3):
        sys.stderr.write('Please pass in JSON file\n')
        exit(1)
    jfile = sys.argv[2]
    jfile_dir = os.path.dirname(jfile)
    with open(jfile) as json_file:
        data = json.load(json_file)

    sources = " "
    for source_file in data['source_files']:
      sources += os.path.abspath(os.path.join(jfile_dir, source_file)) + ' '
    cmd = 'g++ -o {0} {1} {2}'.format(rfile.replace('.cpp',''), rfile, sources)
    if subprocess.call(cmd.split()) != 0:
      exit(1)
    cmd = '{0}'.format(rfile.replace('.cpp',''))
    if subprocess.call(cmd.split()) != 0:
      exit(1)



