% for header in headers:
#include "${header}"
% endfor
#include <klee/klee.h>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <string>

int main() {
  ${class1} v1= new ${class1}; 
  ${class2} v2= new ${class2}; 
 
  % for (i, t_args) in trace:
    % for typ in funcs[i]['args']:
    % if t_args[loop.index].strip() != '*':
    arg${loop.index} = ${t_args[loop.index].strip()};
    % else: 
    arg${loop.index} = *(${typ}*)args::${funcs[i]['arg_gen']}(${loop.index});
    %endif
    % endfor
  <%
    arg_str = ''
    if len(funcs[i]['args']) > 0:
      for j in range(len(funcs[i]['args']) - 1):
        arg_str += 'arg{0}, '.format(j)
      arg_str += 'arg{0}'.format(len(funcs[i]['args']) - 1)
  %>
    v1->${funcs[i]['name']}(${arg_str});
    v2->${funcs[i]['name']}(${arg_str});

  % endfor
}

