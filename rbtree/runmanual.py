from os.path import join
from os import environ
import subprocess

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
    for i in range(100,110):
        mutant = join(blt, 'rbtree', 'mutations', 'rbtree{0}.cpp'.format(i))
        cmd = 'g++ -o manual {0} {1}'.format(rbmanual, mutant)
        subprocess.call(cmd.split())
        cmd = '{0} {1} {2} {3} {4}'.format(manual, steps, 
                                           insert_percent,
                                           remove_percent,
                                           member_percent)
        ret = subprocess.call(cmd.split(), stderr=devnull)
        if ret == 5:
            exit(1)
        elif ret != 0:
            print GREEN + "{0}: found mutant".format(i) + RESET
        else:
            print RED + "{0}: didn't find mutant".format(i) + RESET

    devnull.close()

        

if __name__ == '__main__':
    main()
