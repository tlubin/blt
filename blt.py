import json
import sys
from mako.template import Template 

### Just for testing purposes...
traces = \
[
    [
        { 'symbolic_trace' : 'false', 'symbolic_args' : 'false', 'len' : 20, 'funcs' : ['insert'] },
        { 'symbolic_trace' : 'true', 'symbolic_args' : 'true', 'len' : 2, 'funcs' : ['member', 'get_size', 'insert', 'remove'] }
    ],
    [
        { 'symbolic_trace' : 'false', 'symbolic_args' : 'false', 'len' : 20, 'funcs' : ['insert', 'get_size'] }
    ]
]
###

if __name__ == '__main__':
    if (not sys.argv[1]):
        print 'Please pass in JSON file.'
        exit(1)

    jfile = sys.argv[1]

    with open(jfile) as json_file:
        data = json.load(json_file)

    function_tmpl = Template(filename='templates/functions.mako')
    funcs_str = function_tmpl.render(funcs=data['funcs'], class1=data['class1'],
        class2=data['class2'])

    traces_tmpl = Template(filename='templates/traces.mako')
    traces_str = traces_tmpl.render(traces=traces, class1=data['class1'],
        class2=data['class2'])

    body_tmpl = Template(filename='templates/body.mako')
    body = body_tmpl.render(headers=data['header_files'],
        funcs_str=funcs_str, traces_str=traces_str, ntraces=(len(traces)))

    print body
