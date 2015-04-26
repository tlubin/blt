% for f in funcs:
void call_${f['name']}(${class1}* v1, ${class2}* v2, bool is_sym) {
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
    arg${loop.index} = *(${typ}*)(get_arg(${typ})); // *(${typ}*)args::${f['arg_gen']}(${loop.index});
    % endfor
  }
  % endif
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
    failure();
  % endif
}

% endfor