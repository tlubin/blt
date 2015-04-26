CXX = $(LLVMGCC)/llvm-g++
CXXFLAGS = -emit-llvm -c -g
LD = $(LLVM29)/llvm-link 

TRACE_NO=0
bag_harness:
	bash -c "ulimit -s unlimited"
	python blt.py bag/bag.json > bag/test.cpp
	cd bag ;\
	$(CXX) $(CXXFLAGS) -o BinaryTree.bc BinaryTree.cpp ;\
	$(CXX) $(CXXFLAGS) -o DynamicIntBag.bc DynamicIntBag.cpp ;\
	$(CXX) $(CXXFLAGS) -o LilIntBag.bc LilIntBag.cpp ;\
	$(CXX) $(CXXFLAGS) -o args.bc  args.cpp ;\
	$(CXX) $(CXXFLAGS) -o test.bc -I $(KLEE)/include test.cpp ;\
	$(LD) -o combined.bc  DynamicIntBag.bc  LilIntBag.bc  BinaryTree.bc args.bc test.bc ;\
	klee -emit-all-errors combined.bc $(TRACE_NO) 

.PHONY: bag_harness

calcs_harness:
	bash -c "ulimit -s unlimited"
	python blt.py calcs/calcs.json > calcs/test.cpp
	cd calcs/ ;\
	$(CXX) $(CXXFLAGS) -o  old_calc.bc  old_calc.cpp ;\
	$(CXX) $(CXXFLAGS) -o  new_calc.bc  new_calc.cpp ;\
	$(CXX) $(CXXFLAGS) -o test.bc -I $(KLEE)/include test.cpp ;\
	$(LD) -o  combined.bc  old_calc.bc  new_calc.bc  test.bc ;\
	klee -emit-all-errors  combined.bc $(TRACE_NO)

.PHONY: calcs_harness 
