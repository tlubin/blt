import subprocess

i = 0
while i < 1000:
    subprocess.call(
            'python mutate.py rbtree.cpp mutations/rbtree{0}.cpp'.format(i),
            shell=True)
    if subprocess.call(
            'g++ -c -o mutations/out.o mutations/rbtree{0}.cpp'.format(i),
            shell=True) == 0:
        i += 1
