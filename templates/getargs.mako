% for header in headers:
#include "${header}"
% endfor
#include <cstdlib>
#include <iostream>
#include <cassert>

void failure() {
    exit(0);
    return;
}

int main(int argc, const char* argv[]) {
    srand(${seed});
    ${class1} *v1= new ${class1}; 
    ${class2} *v2= new ${class2}; 
    <%
      sym_arg_num = 0
    %>
    % for node in trace:
    % for f in node['calls']:
    ## Inside of blt.py, I take care of shortened symbolic trace nodes
    ## Here, I take care of shortened concrete trace, symbolic argument nodes
    <%
      func = [func for func in funcs if func['name']==f][0]
      if node['symbolic_args'] == 'true' and sym_arg_num + len(func['args']) > len(sym_args):
      	 break
    %>
    ## Push the name of the function
    std::cout << "${f}";

    % if node['symbolic_args'] == 'false':
    ## Get the concrete arguments by calling the appropriate generator
    % for typ in func['args']:
    % if 'arg_gen' in func.keys():
    ${typ} arg${loop.parent.parent.index}_${loop.parent.index}_${loop.index} = *(${typ}*)(args::${funcs['arg_gen']}(${loop.index}));
    std::cout << ",$BLT_GENERATED_ARG$";
    % else: 
    ${typ} arg${loop.parent.parent.index}_${loop.parent.index}_${loop.index} = *(${typ}*)(blt_args::get_arg("${typ}"));
    std::cout << "," << arg${loop.parent.parent.index}_${loop.parent.index}_${loop.index};
    % endif
    % endfor

    % else:
    ## Get the symbolic arguments from passed in sym_args
    % for typ in func['args']:
    ${typ} arg${loop.parent.parent.index}_${loop.parent.index}_${loop.index} = ${sym_args[sym_arg_num]};
    std::cout << "," << arg${loop.parent.parent.index}_${loop.parent.index}_${loop.index};
    <%
      sym_arg_num += 1
    %>
    % endfor
    % endif

    <%
    arg_str = ''
    if len(func['args']) > 0:
      for j in range(len(func['args']) - 1):
        arg_str += 'arg{0}_{1}_{2}, '.format(loop.parent.index, loop.index, j)
      arg_str += 'arg{0}_{1}_{2}'.format(loop.parent.index, loop.index, len(func['args']) - 1)
    %>
    % if func['return'] != 'void':
    if (v1->${func['name']}(${arg_str}) != v2->${func['name']}(${arg_str}))
      failure();
    % else:
    v1->${func['name']}(${arg_str});
    v2->${func['name']}(${arg_str});
    % endif
    std::cout << "\n";
    % endfor
    % endfor
}
