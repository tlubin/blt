#BLT: discover differences in the execution of two versions of your code by executing traces symbolically and concretely.

#How to Use:
- Dependencies: KLEE (and related dependencies), python 2.7, Mako
- Define environment variables $KLEE, $LLVM29, and $LLVMGCC to point to the source for your installation of KLEE, llvm-2.9, and llvm-gcc
- Required files:
  - Source and header file of old implementation of code
  - Source and header file of new implementation of code
  - (optional) args.cpp and args.hpp file specifying argument-generating functions for each of the object methods 
  - JSON file specifying the following:
      - the header file names
      - functions (name, args, return, (optional: argument generator function name))
      - traces (symbolic_trace, symbolic_args, len, funcs)
      - for more details, see provided examples (bag.json or calcs/json)
- Run Examples:
    - Bags: Run "python [path-to_blt.py] [path_to_bag.json] to execute a concrete-symbolic trace on two versions of a bag data structure
    - Calcs: Run "python [path_to_blt.py] [path_to_calcs.json]" to execute a concrete-symbolic trace on two versions of a simple calculator


Created by Aaron Bembenek, Lily Tsai, Todd Lubin

CS260r, 2015
