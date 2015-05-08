% for header in headers:
#include "${header}"
% endfor
#include <cstdlib>
#include <iostream>
#include <cassert>

int main(int argc, const char* argv[]) {
    srand(${seed});
    ${class1} *v1= new ${class1}; 
    ${class2} *v2= new ${class2}; 
    % for node in trace:
    % for i in range(node['len']):
    <%
      func = [func for func in funcs if func['name']==node['calls'][i]][0]
    %>

    ## Push the name of the function
    std::cout << "${node['calls'][i]}";
    % if node['symbolic_args'] == 'false':
    ## Get the concrete arguments by calling the appropriate generator
    % for typ in func['args']:
    % if 'arg_gen' in func.keys():
    ${typ} arg${loop.parent.parent.index}_${loop.parent.index}_${loop.index} = *(${typ}*)(args::${func['arg_gen']}(${loop.index}));
    std::cout << ",$BLT_GENERATED_ARG$";
    % else: 
    ${typ} arg${loop.parent.parent.index}_${loop.parent.index}_${loop.index} = *(${typ}*)(blt_args::get_arg("${typ}"));
    std::cout << "," << arg${loop.parent.parent.index}_${loop.parent.index}_${loop.index};
    % endif
    % endfor

    % else:
    ## Use the symbolic arguments from passed in sym_args
    % for j,typ in enumerate(func['args']):
    ${typ} arg${loop.parent.parent.index}_${loop.parent.index}_${loop.index} = ${node['args'][i][j]};
    std::cout << "," << arg${loop.parent.parent.index}_${loop.parent.index}_${loop.index};
    % endfor
    % endif
    std::cout << std::endl;
    <%
    arg_str = ''
    if len(func['args']) > 0:
      for j in range(len(func['args']) - 1):
        arg_str += 'arg{0}_{1}_{2}, '.format(loop.parent.index, loop.index, j)
      arg_str += 'arg{0}_{1}_{2}'.format(loop.parent.index, loop.index, len(func['args']) - 1)
    %>
    % if func['return'] != 'void':
    if (v1->${func['name']}(${arg_str}) != v2->${func['name']}(${arg_str}))
      exit(0);
    % else:
    v1->${func['name']}(${arg_str});
    v2->${func['name']}(${arg_str});
    % endif
    % endfor
    % endfor
}
