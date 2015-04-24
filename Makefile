CXX = $(LLVMGCC)/llvm-g++
CXXFLAGS = -emit-llvm -c -g
LD = $(LLVM29)/llvm-link 

bag_harness:
	bash -c "ulimit -s unlimited"
	python blt.py bag/bag.json
	mv harness.cpp bag/;
	cd bag/; \
	$(CXX) $(CXXFLAGS) -o  BinaryTree.bc BinaryTree.cpp ;\
	$(CXX) $(CXXFLAGS) -o  DynamicIntBag.bc DynamicIntBag.cpp ;\
	$(CXX) $(CXXFLAGS) -o  LilIntBag.bc LilIntBag.cpp ;\
	$(CXX) $(CXXFLAGS) -o  Trace.bc Trace.cpp ;\
	$(CXX) $(CXXFLAGS) -o  args.bc  args.cpp ;\
	$(CXX) $(CXXFLAGS) -o harness.bc -I $(KLEE)/include harness.cpp ;\
	$(LD) -o combined.bc  DynamicIntBag.bc  LilIntBag.bc  BinaryTree.bc  Trace.bc  args.bc harness.bc ;\
	klee -emit-all-errors  combined.bc

.PHONY: bag_harness 

calcs_harness:
	bash -c "ulimit -s unlimited"
	python blt.py calcs/calcs.json
	mv harness.cpp calcs/;
	cd calcs/ ;\
	$(CXX) $(CXXFLAGS) -o  old_calc.bc  old_calc.cpp ;\
	$(CXX) $(CXXFLAGS) -o  new_calc.bc  new_calc.cpp ;\
	$(CXX) $(CXXFLAGS) -o  Trace.bc Trace.cpp ;\
	$(CXX) $(CXXFLAGS) -o harness.bc -I $(KLEE)/include harness.cpp ;\
	$(LD) -o  combined.bc  old_calc.bc  new_calc.bc  Trace.bc harness.bc ;\
	klee -emit-all-errors  combined.bc

.PHONY: calcs_harness 
