#BLT: discover differences in the execution of two versions of your code by executing traces symbolically and concretely.

#How to Use:
- Dependencies: KLEE (and related dependencies), python 2.7, Mako (install with pip)
- Define environment variables $KLEE, $LLVM29, and $LLVMGCC to point to the source for your installation of KLEE, llvm-2.9, and llvm-gcc
- Required files:
  - Source and header file of old implementation of the API
  - Source and header file of new implementation of the API 
  - Required files for either implementations of the API 
  - (optional) args.cpp and args.hpp file specifying argument-generating functions for each of the API methods 
  - JSON file specifying the following:
      - the class names
      - the header file names
      - the source file names
      - functions (name, args, return, (optional: argument generator function name))
      - traces (symbolic_trace, symbolic_args, len, funcs)

      For example, say you have two different queue implementations you want
      to compare, ListQueue and ArrayQueue. Here is a possible JSON specifying two
      traces, one which randomly chooses between push and pop for 100 calls (using
      a user-supplied argument generator for push called "push_arg_gen"),
      pops a symbolic value, and then compares the sizes of the two queues, and one
      which symbolically calls all the functions simultaneously on symbolic values
      for a depth of 10 calls. 

        ```{
          "class1" : "ListQueue",
          "class2" : "ArrayQueue",
          "header_files" : ["ListQueue.hpp", "ArrayQueue.hpp"],
          "source_files" : ["ListQueue.cpp", "ArrayQueue.cpp"],
          "funcs" : [
            { "name" : "push",
              "args" : ["int"],
              "return" : "void",
              "arg_gen" : "`push_arg_gen`" },
            { "name" : "pop",
              "args" : [],
              "return" : "int" },
            { "name" : "get_size",
              "args" : [],
              "return" : "int" }
          ],
          "traces" : [
            [
              { "symbolic_trace" : "false",
                "symbolic_args" : "false",
                "len" : 100,
                "funcs" : ["push", "pop"] },
              { "symbolic_trace" : "false",
                "symbolic_args" : "true",
                "len" : 1,
                "funcs" : ["pop"] },
              { "symbolic_trace" : "false",
                "symbolic_args" : "false",
                "len" : 1,
                "funcs" : ["get_size"] }
            ],
            [
              { "symbolic_trace" : "true",
                "symbolic_args" : "true",
                "len" : 10,
                "funcs" : ["push", "pop", "get_size"]
              }
            ]
          ]
        }```

      - see also bag/bag.json and calcs/calcs.json for more examples

- Run Examples:
    - Bags: Run "python [path-to_blt.py] [path_to_bag.json] to execute a concrete-symbolic trace on two versions of a bag data structure
    - Calcs: Run "python [path_to_blt.py] [path_to_calcs.json]" to execute a concrete-symbolic trace on two versions of a simple calculator
    - Output placed in blt_tmp folder in example folders

- Run Replays:
    - Run "python [path-to_run_replay.py] [path_to_replay[num].cpp] [path_to_bag.json]

Created by Aaron Bembenek, Lily Tsai, Todd Lubin

CS260r, 2015
