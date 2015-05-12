# Run with python3 in order to use subprocess timeout
# This is needed for mutations that cause infinite loops :/

from os.path import join
from os import environ
import subprocess
import sys

GREEN = '\033[1m\033[32m'
RED = '\033[1m\033[31m'
RESET = '\033[0m'

steps = 100000
insert_percent = 50
remove_percent = 25
member_percent = 25

def main():
    if 'BLT' not in environ:
        sys.stderr.write('set BLT environment variable\n')
        exit(1)
    blt = environ['BLT']
    rbmanual = join(blt, 'rbtree', 'rbmanual.cpp')
    manual = join(blt, 'rbtree', 'manual')
    devnull = open('/dev/null', 'w')
    found = 0
    mutants = range(1000)
    for i in mutants:
        if i % 10 == 0:
            sys.stderr.write('CHECKPOINT: {0} of {1}\n'.format(found, i - mutants[0]))
        mutant = join(blt, 'rbtree', 'mutations', 'rbtree{0}.cpp'.format(i))
        cmd = 'g++ -o manual {0} {1}'.format(rbmanual, mutant)
        subprocess.call(cmd.split())
        cmd = '{0} {1} {2} {3} {4}'.format(manual, steps, 
                                           insert_percent,
                                           remove_percent,
                                           member_percent)
        timeout = 0
        try:
            ret = subprocess.call(cmd.split(), stderr=devnull, timeout=15)
        except subprocess.TimeoutExpired:
            timeout = 1
        if timeout == 1:
            print("{0} timed out".format(i))
        elif ret == 0:
            print("{0}: didn't find mutant".format(i))
        elif ret == 5:
            exit(1)
        else:
            found += 1
            print("{0}: found mutant".format(i))


    print("{0} of {1} FOUND".format(found, len(mutants)))

    devnull.close()

        

if __name__ == '__main__':
    main()
