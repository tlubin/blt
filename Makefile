CXX = llvm-g++
CXXFLAGS = -emit-llvm -c -g -S
LD = llvm-link
KLEE_PATH = ~/klee/include

klee_harness:
	bash -c "ulimit -s unlimited"
	$(CXX) $(CXXFLAGS) -o old_calc.bc old_calc.cpp
	$(CXX) $(CXXFLAGS) -o new_calc.bc new_calc.cpp
	$(CXX) $(CXXFLAGS) -o klee_harness.bc -I $(KLEE_PATH) klee_harness.cpp
	$(LD) -o combined.bc old_calc.bc new_calc.bc klee_harness.bc
	klee -emit-all-errors combined.bc

.PHONY: klee_harness
