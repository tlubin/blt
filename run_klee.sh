#!/bin/sh

if [ -z "$KLEE" ]; then
    echo "need to define KLEE environment variable to top of klee directory"
    exit 1
fi

if [ -z "$LLVMGCC" ]; then
    echo "need to define LLVMGCC environment variable to location of llvm-gcc binary"
    exit 1
fi

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 filename"
    exit 1
fi

export PATH=$PATH:$KLEE/Release+Asserts/bin:$LLVMGCC

klee_include="$KLEE/include"
llvm-gcc -std=c99 -I $klee_include --emit-llvm -c -g $1
filename_o=`echo $1 | sed 's/\.c/\.o/'`
klee -emit-all-errors $filename_o

