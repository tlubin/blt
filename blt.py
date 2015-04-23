import json

with open('bag.json') as json_file:
    data = json.load(json_file)

replacements = []

def add_replacement(template, code):
    replacements.append((template,code))

try:
    add_replacement("#OLD_HEADER", data["file1"][0]);
    add_replacement("#NEW_HEADER", data["file2"][0]);
    add_replacement("#FUNC_COUNT", str(len(data["funcs"])))
    add_replacement("#OLD_IMPL", data["file1"][0].split('.')[0])
    add_replacement("#NEW_IMPL", data["file2"][0].split('.')[0])

except KeyError, k:
    print "JSON file should have key " + str(k)

with open('harness.cpp') as harness_file:
    harness_data = harness_file.read()

for rep in replacements:
    harness_data = harness_data.replace(rep[0],rep[1])

with open('harness_tmp.cpp', 'w') as harness_tmp:
    harness_tmp.write(harness_data)

print replacements
