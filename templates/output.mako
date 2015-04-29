% for header in headers:
#include "${header}"
% endfor
#include <cassert>
#include <cstdlib>

void failure() {
  assert(0);
}

int main() {
  ${class1} *v1= new ${class1}; 
  ${class2} *v2= new ${class2}; 

  % for (i, t_args) in trace:
  % for typ in funcs[i]['args']:
  % if t_args[loop.index] != '*':
  ${typ} arg${loop.parent.index}_${loop.index} = ${t_args[loop.index]};
  % else: 
  ${typ} arg${loop.parent.index}_${loop.index} = *(${typ}*)args::${funcs[i]['arg_gen']}(${loop.index});
  % endif
  % endfor
  <%
  arg_str = ''
  if len(funcs[i]['args']) > 0:
    for j in range(len(funcs[i]['args']) - 1):
      arg_str += 'arg{0}_{1}, '.format(loop.index, j)
    arg_str += 'arg{0}_{1}'.format(loop.index, len(funcs[i]['args']) - 1)
  %>
  % if funcs[i]['return'] == 'void':
  v1->${funcs[i]['name']}(${arg_str});
  v2->${funcs[i]['name']}(${arg_str});
  % else:
  ${funcs[i]['return']} r1 = v1->${funcs[i]['name']}(${arg_str});
  ${funcs[i]['return']} r2 = v2->${funcs[i]['name']}(${arg_str});
  if (r1 != r2) failure();

  % endif
  % endfor
}

