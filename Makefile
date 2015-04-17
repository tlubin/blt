CXX = $(LLVMGCC)/llvm-g++
CXXFLAGS = -emit-llvm -c -g
LD = ~/installations/llvm-2.9/Release+Asserts/bin/llvm-link 

klee_harness:
	bash -c "ulimit -s unlimited"
	$(CXX) $(CXXFLAGS) -o old_calc.bc old_calc.cpp
	$(CXX) $(CXXFLAGS) -o new_calc.bc new_calc.cpp
	$(CXX) $(CXXFLAGS) -o concolic.bc -I $(KLEE)/include concolic.cpp
	$(LD) -o combined.bc old_calc.bc new_calc.bc concolic.bc
	klee -emit-all-errors combined.bc

.PHONY: concolic 
