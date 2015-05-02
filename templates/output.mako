% for header in headers:
#include "${header}"
% endfor
#include <cassert>
#include <cstdlib>
#define SEED 260

void failure() {
  assert(0);
}

int main() {
  srand(SEED);

  ${class1} *v1= new ${class1}; 
  ${class2} *v2= new ${class2}; 
  % for (f, args) in calls_args:
  <%
  func = [func for func in funcs if func['name']==f][0]
  %>
  % for arg in args:
  <%
  typ = func['args'][loop.index]
  %>
  % if arg == "GEN":
  ${typ} arg${loop.parent.index}_${loop.index} = *(${typ}*)args::${func['arg_gen']}(${loop.index});  
  % else:
  ${typ} arg${loop.parent.index}_${loop.index} = ${arg};
  % endif
  % endfor
  <%
  arg_str = ''
  if len(func['args']) > 0:
    for j in range(len(func['args']) - 1):
      arg_str += 'arg{0}_{1}, '.format(loop.index, j)
    arg_str += 'arg{0}_{1}'.format(loop.index, len(func['args']) - 1)
  %>
  % if func['return'] == 'void':
  v1->${func['name']}(${arg_str});
  v2->${func['name']}(${arg_str});
  % else:
  ${func['return']} r1 = v1->${func['name']}(${arg_str});
  ${func['return']} r2 = v2->${func['name']}(${arg_str});
  if (r1 != r2) failure();
  % endif
  % endfor
}

