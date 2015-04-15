klee_harness:
	bash -c "ulimit -s unlimited"
	llvm-g++ -I ~/installations/klee/include -emit-llvm -c -g klee_harness.cpp
	klee -emit-all-errors klee_harness.o

.PHONY: klee_harness
