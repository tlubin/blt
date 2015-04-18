#!/bin/sh

if [ -z "$KLEE" ]; then
    echo "need to define KLEE environment variable to top of klee directory"
    exit 1
fi

export PATH=$PATH:$KLEE/tools/ktest-tool

ktest-tool --write-ints klee-last/test*.ktest
