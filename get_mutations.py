import os
import sys
import string

blt = os.environ['BLT']
write_fd = open(os.path.join(blt, 'stats/mutants.txt'), 'w')

for i, outf in enumerate(sorted(os.listdir(os.path.join(blt, 'rbtree/mutations')))):
    found = 0
    read_fd = open(os.path.join(blt, 'rbtree/mutations', outf),'r')
    for line in read_fd.readlines():
        if 'XXX' in line:
            index = string.find(line, 'original code was: ') + len('original code was: ')
            write_fd.write(str(i) + '$ ' + line[index:-3])
            found = 1
        elif found:
            write_fd.write('$ ' + line)
            break

