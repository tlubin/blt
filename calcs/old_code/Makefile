CXX = $(LLVMGCC)/llvm-g++
CXXFLAGS = -emit-llvm -c -g
LD = $(LLVM29)/llvm-link

threads_harness:
	bash -c "ulimit -s unlimited"
	$(CXX) $(CXXFLAGS) -o old_calc.bc old_calc.cpp
	$(CXX) $(CXXFLAGS) -o new_calc.bc new_calc.cpp
	$(CXX) $(CXXFLAGS) -o threads_harness.bc -I $(KLEE)/include threads_harness.cpp
	$(LD) -o combined.bc old_calc.bc new_calc.bc threads_harness.bc
	klee -emit-all-errors combined.bc

.PHONY: threads_harness
