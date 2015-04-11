fake_harness: fake_harness.cpp
	bash -c "ulimit -s unlimited"
	llvm-g++ -I ~/klee/include -emit-llvm -c -g fake_harness.cpp
	klee -emit-all-errors fake_harness.o

.PHONY: fake_harness 
