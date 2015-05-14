#BLT

##Discover differences in the behavior of two C++ classes that implement the same API through the power of combined concrete and symbolic testing.

####How to Use:
- Dependencies:
  - KLEE (and related dependencies)
  - Python 2.7
  - Mako (install with pip)
- You need to define the following environment variables:
  - `KLEE` - your KLEE directory (e.g. `~/klee`)
  - `BLT` - your BLT directory (e.g. `~/blt`)
  - `LLVM29` - the location of `llvm-link` for llvm 2.9
  - `LLVMGCC` - the location of `llvm-g++`
- Option 1: Compare two different C++ classes that implement the same API. You must provide:
  - Source and header file of old implementation of the API
  - Source and header file of new implementation of the API 
  - Required files for either implementations of the API 
  - (optional) `args.cpp` and `args.hpp` specifying a class `args` with methods that generate arguments for API calls selected in the JSON (see next point) 
  - JSON file defining an object with the following properties:
      - `"class1"` - name of first class 
      - `"class2"` - name of second class 
      - `"header_files"` - list of header files
      - `"source_files"` - list of source files
      - `"funcs"` - list of functions shared by both classes, where each function is represented as an object with the properties:
        - `"name"` - name of function
        - `"args"` - list of argument types
        - `"return"` - type of return value
        - `"arg_gen"` - name of custom argument generator to use (optional)
      - `"traces"` - a list of traces, where each trace is represented as a list of objects with the properties:
        - `"symbolic_trace"` - Use symbolic function calls? Specify "true" or "false"
        - `"symbolic_args"` - Use symbolic arguments? Specify "true" or "false"
        - `"len"` - integer specifying depth of trace
        - `"funcs"` - list of functions to choose from

      For example, say you have two different queue implementations you want
      to compare, `ListQueue` and `ArrayQueue`. Here is a possible JSON specifying two
      traces, one which randomly chooses between `push` and `pop` for 100 calls (using
      a user-supplied argument generator for `push` called `push_arg_gen`),
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
- Option 2: Find correctness bugs (e.g. internal assertion errors, null-pointer dereferences) in a single C++ class that implements an API:
    - Set `"class1"` and `"class2"` to both be the name of the C++ class under test 
    - Include all other properties as before

- Running BLT:
    - `python path/to/blt.py --trace path/to/json_file.json`
    - Output placed in `blt_tmp` folder in same directory as JSON file
    - E.g. `python blt.py --trace bag/bag.json`

- Run replays:
    - `python path/to/blt.py --replay path/to/replay.cpp path/to/json_file.json`
    - `python path/to/blt.py --replay-all path/to/replay/dir path/to/json_file.json`
    - E.g. `python blt.py --replay bag/blt_tmp/replay0_0.cpp bag/bag.json`

Created by Aaron Bembenek, Lily Tsai, Todd Lubin

CS260r, 2015
