#BLT

##Discover differences in the behavior of two C++ classes by executing traces symbolically and concretely.

####How to Use:
- Dependencies:
  - KLEE (and related dependencies)
  - Python 2.7
  - Mako (install with pip)
- You need to define the following environment variables:
  - `KLEE` to your KLEE directory (e.g. `~/klee`)
  - `BLT` to your BLT directory (e.g. `~/blt`)
  - `LLVM29` to the location of `llvm-link` version 2.9
  - `LLVMGCC` to the location of `llvm-gcc` version 2.9
- Required files you must provide:
  - Source and header file of old implementation of the API
  - Source and header file of new implementation of the API 
  - Required files for either implementations of the API 
  - (optional) `args.cpp` and `args.hpp` file specifying a class `args` with argument-generating functions to be used for selected API methods 
  - JSON file specifying the following:
      - the class names (`class1` and `class2`)
      - the header file names (a list `header_files`)
      - the source file names (a list `source_files`)
      - functions (a list `funcs` of objects with the properties `name`, `args`, `return`, and optionally `arg_gen` for custom argument generator function)
      - traces (a list `traces` of objects with the properties `symbolic_trace`, `symbolic_args`, `len`, `funcs`)

      For example, say you have two different queue implementations you want
      to compare, `ListQueue` and `ArrayQueue`. Here is a possible JSON specifying two
      traces, one which randomly chooses between push and pop for 100 calls (using
      a user-supplied argument generator for push called `push_arg_gen`),
      pops a symbolic value, and then compares the sizes of the two queues, and one
      which symbolically calls all the functions simultaneously on symbolic values
      for a depth of 10 calls. 

        ```javascript
        {
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
        }
        ```
        
      See also `bag/bag.json` and `calcs/calcs.json` for more examples.

- Running BLT:
    - `python path/to/blt.py path/to/json_file.json`
    - Output placed in `blt_tmp` folder in same directory as JSON file
    - E.g. `python blt.py bag/bag.json`

- Run replays:
    - `python path/to/blt.py --replay path/to/replay.cpp path/to/json_file.json`
    - E.g. `python run_replay.py bag/blt_tmp/replay0.cpp bag/bag.json`

Created by Aaron Bembenek, Lily Tsai, Todd Lubin

CS260r, 2015
