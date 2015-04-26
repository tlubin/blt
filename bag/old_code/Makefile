CXX = $(LLVMGCC)/llvm-g++
CXXFLAGS = -emit-llvm -c -g
LD = $(LLVM29)/llvm-link 

bag_harness:
	bash -c "ulimit -s unlimited"
	$(CXX) $(CXXFLAGS) -o BinaryTree.bc BinaryTree.cpp 
	$(CXX) $(CXXFLAGS) -o DynamicIntBag.bc DynamicIntBag.cpp
	$(CXX) $(CXXFLAGS) -o LilIntBag.bc LilIntBag.cpp
	$(CXX) $(CXXFLAGS) -o Trace.bc Trace.cpp
	$(CXX) $(CXXFLAGS) -o args.bc args.cpp
	$(CXX) $(CXXFLAGS) -o bag_harness.bc -I $(KLEE)/include bag_harness.cpp
	$(LD) -o combined.bc DynamicIntBag.bc LilIntBag.bc BinaryTree.bc Trace.bc args.bc bag_harness.bc
	klee -emit-all-errors combined.bc

.PHONY: bag_harness 
