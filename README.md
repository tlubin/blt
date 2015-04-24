#BLT:
a tool to discover differences in the execution of two versions of your code by executing traces symbolically and concretely.

#How to Use:
- Dependencies: KLEE (and related dependencies), python 2.7
- Define environment variables $KLEE, $LLVM29, and $LLVMGCC to point to the source for your installation of KLEE, llvm-2.9, and llvm-gcc
- Required files:
  - Source and header file of old implementation of code
  - Source and header file of new implementation of code
  - (optional) args.cpp and args.hpp file specifying argument-generating functions for each of the object methods 
  - JSON file specifying the header file names, function names and types, argument types, (optional: argument generator function name)
      - for more details, see provided examples (bag.json or calcs/json)
  - Specification of traces in Traces.cpp (see Traces.cpp in bag or calcs example)
- Run Examples:
    - Bags: Run "make bag_harness" to execute a concrete-symbolic trace on two versions of a bag data structure
    - Calcs: Run "make calc_harness" to execute a concrete-symbolic trace on two versions of a simple calculator


Created by Aaron Bembenek, Lily Tsai, Todd Lubin

CS260r, 2015
