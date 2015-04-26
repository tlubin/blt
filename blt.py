import json
import sys

if (not sys.argv[1]):
    print "please pass in JSON file"
    exit(1)

jfile = sys.argv[1]

with open(jfile) as json_file:
    data = json.load(json_file)

glob_replacements = []
func_replacements = {}

def add_func_replacements(f,x):
    replacement = []
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
        check_equality += "new_impl->{0};\n  ".format(func_call)
        check_equality += "old_impl->{0};".format(func_call)
    else:
        check_equality += "if (new_impl->{0} != old_impl->{0}) failure();".format(func_call)

    if len(f["args"]):
        make_args_symbolic = "if (is_sym) {\n    " + make_args_symbolic + "  }"
        make_args_concrete = "else {\n    " + make_args_concrete + "  }"

    replacement.append(("#FUNC_NUM#", str(x)))
    replacement.append(("#DEFINE_ARGS#", define_args))
    replacement.append(("#MAKE_ARGS_SYMBOLIC#", make_args_symbolic))
    replacement.append(("#MAKE_ARGS_CONCRETE#", make_args_concrete))
    replacement.append(("#CHECK_EQUALITY#", check_equality))
    func_replacements[x] = replacement

try:
    glob_replacements.append(("#OLD_HEADER#", data["file1"][0]));
    glob_replacements.append(("#NEW_HEADER#", data["file2"][0]));
    glob_replacements.append(("#FUNC_COUNT#", str(len(data["funcs"]))))
    glob_replacements.append(("#OLD_IMPL#", data["file1"][0].split('.')[0]))
    glob_replacements.append(("#NEW_IMPL#", data["file2"][0].split('.')[0]))

    for x,f in enumerate(data["funcs"]):
        add_func_replacements(f,x)

except KeyError, k:
    print "JSON file should have key " + str(k)

with open('harness_temp.cpp') as harness_file:
    harness_data = harness_file.read()

for rep in glob_replacements:
    harness_data = harness_data.replace(rep[0],rep[1])

# HANDLE TEMPLATES
lines = harness_data.splitlines(True)
temp = ""
for i in range(len(lines)):
    if lines[i].strip() == '##FUNCTION_TEMP##':
        front_temp = temp
        temp = ""
    elif lines[i].strip() == '##END_FUNCTION_TEMP##':
       function_temp = temp
       temp = ""
    elif lines[i].strip() == '##CASE_TEMP##':
        mid_temp = temp
        temp = ""
    elif lines[i].strip() == '##END_CASE_TEMP##':
        case_temp = temp
        temp = ""
    else:
        temp += lines[i]
back_temp = temp

call_func = ""
switch = ""
for i,f in enumerate(data["funcs"]):
    f_temp = function_temp
    c_temp = case_temp
    f_rep = func_replacements[i]
    for rep in f_rep:
        f_temp = f_temp.replace(rep[0],rep[1])
        c_temp = c_temp.replace(rep[0],rep[1])
    call_func += f_temp
    switch += c_temp

# WRITE TO FILE
with open('harness.cpp', 'w') as harness_tmp:
    harness_tmp.write(front_temp)
    harness_tmp.write(call_func)
    harness_tmp.write(mid_temp)
    harness_tmp.write(switch)
    harness_tmp.write(back_temp)


