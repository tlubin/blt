import json

with open('bag/bag.json') as json_file:
    data = json.load(json_file)

glob_replacements = []
func_replacements = []

def add_func_replacements(f):
    replacement = {}
    # DEFINE_ARGS and MAKE_ARGS_SYMBOLIC
    define_args = ""
    make_args_symbolic = ""
    make_args_concrete = ""
    args = "" # e.g. "arg1, arg2"
    check_equality = ""
    for i,arg in enumerate(f["args"]):
        define_args += "{0} arg{1};\n".format(arg,i)
        make_args_symbolic += "klee_make_symbolic(&arg{0}, sizeof(arg{0}),\"arg{0}\");\n".format(i)
        make_args_concrete += "arg{0} = *({1}*)args::{2}({0});\n".format(i,arg,f["arg_gen"])
        args += "arg{0}, ".format(i)
    args = args[:-2]
    func_call = "{0}({1})".format(f["name"], args)
    if f["return"] == "void":
        check_equality += "new_impl->{0};\n".format(func_call)
        check_equality += "old_impl->{0};\n".format(func_call)
    else:
        check_equality += "if (new_impl->{0} != old_impl->{0}) failure();".format(func_call)

    replacement["#DEFINE_ARGS#"] = define_args
    replacement["#MAKE_ARGS_SYMBOLIC#"] = make_args_symbolic
    replacement["#MAKE_ARGS_CONCRETE#"] = make_args_concrete
    replacement["#CHECK_EQUALITY#"] = check_equality
    func_replacements.append(replacement)

try:
    glob_replacements.append(("#OLD_HEADER#", data["file1"][0]));
    glob_replacements.append(("#NEW_HEADER#", data["file2"][0]));
    glob_replacements.append(("#FUNC_COUNT#", str(len(data["funcs"]))))
    glob_replacements.append(("#OLD_IMPL#", data["file1"][0].split('.')[0]))
    glob_replacements.append(("#NEW_IMPL#", data["file2"][0].split('.')[0]))

    for f in data["funcs"]:
        add_func_replacements(f)

except KeyError, k:
    print "JSON file should have key " + str(k)



with open('harness.cpp') as harness_file:
    harness_data = harness_file.read()

for rep in glob_replacements:
    harness_data = harness_data.replace(rep[0],rep[1])

with open('harness_tmp.cpp', 'w') as harness_tmp:
    harness_tmp.write(harness_data)
