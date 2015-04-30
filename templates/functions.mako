void failure(std::stringstream* ss) {
//  std::fstream fs;
//  fs.open("trace", std::fstream::out | std::fstream::app);
//  fs << ss->str() << "*****\n";
//  fs.close();
  assert(0);
}

% for f in funcs:
void call_${f['name']}(${class1}* v1, ${class2}* v2, bool is_sym, std::stringstream* ss) {
//  (*ss) << "${f['name']}";
  % if len(f['args']) > 0:
  % for typ in f['args']:
  ${typ} arg${loop.index};
  % endfor
  if (is_sym) {
    % for i in range(len(f['args'])):
    klee_make_symbolic(&arg${i}, sizeof(arg${i}), "arg${i}");
    % endfor
  } else {
    % for typ in f['args']:
    % if 'arg_gen' in f.keys() and f['arg_gen'] == "":
    arg${loop.index} = *(${typ}*)args::${f['arg_gen']}(${loop.index});
//    (*ss) << ",*";
    % else: 
    arg${loop.index} = *(${typ}*)(get_arg("${typ}"));
//    (*ss) << "," << arg${loop.index};
    %endif
    % endfor
  }
  % endif
//  (*ss) << "\n";
  <%
  arg_str = ''
  if len(f['args']) > 0:
    for i in range(len(f['args']) - 1):
      arg_str += 'arg{0}, '.format(i)
    arg_str += 'arg{0}'.format(len(f['args']) - 1)
  %>
  % if f['return'] == 'void':
  v1->${f['name']}(${arg_str});
  v2->${f['name']}(${arg_str});
  % else:
  ${f['return']} r1 = v1->${f['name']}(${arg_str});
  ${f['return']} r2 = v2->${f['name']}(${arg_str});
  if (r1 != r2)
    failure(ss);
  % endif
}

% endfor
