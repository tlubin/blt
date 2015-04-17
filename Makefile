CXX = $(LLVMGCC)/llvm-g++
CXXFLAGS = -emit-llvm -c -g
LD = $(LLVMGCC)/llvm-link 

klee_induct:
	bash -c "ulimit -s unlimited"
	$(CXX) $(CXXFLAGS) -I $(KLEE)/include klee_induct.cpp
	klee -emit-all-errors klee_induct.o 

klee_harness:
	bash -c "ulimit -s unlimited"
	$(CXX) $(CXXFLAGS) -o old_calc.bc old_calc.cpp
	$(CXX) $(CXXFLAGS) -o new_calc.bc new_calc.cpp
	$(CXX) $(CXXFLAGS) -o klee_harness.bc -I $(KLEE)/include klee_harness.cpp
	$(LD) -o combined.bc old_calc.bc new_calc.bc klee_harness.bc
	klee -emit-all-errors combined.bc

.PHONY: klee_harness
