% for header in headers:
#include "${header}"
% endfor
#include <cstdlib>
#include <sstream>
#include <iostream>

% for f in funcs:
void call_${f['name']}(std::stringstream* ss) {
  (*ss) << "${f['name']}";
  % if len(f['args']) > 0:
  % for typ in f['args']:
  ${typ} arg${loop.index};
  % endfor
  % for typ in f['args']:
  % if 'arg_gen' in f.keys():	
  (*ss) << ",$BLT_GENERATED_ARG$";
  % else: 
  arg${loop.index} = *(${typ}*)(blt_args::get_arg("${typ}"));
  (*ss) << "," << arg${loop.index};
  %endif
  % endfor
  % endif
  (*ss) << "\n";
}
% endfor

int main(int argc, const char* argv[]) {
    srand(${seed});
    std::stringstream* ss = new std::stringstream();
    <%
      nodes = [x for x in trace if x['symbolic_args'] == 'false']
      sym_call_num = 0
    %>
    % for node in nodes:
    % if node['symbolic_trace'] == 'false':
    % for f in node['calls']:
    call_${f}(ss);
    % endfor
    % else:
    % for _ in range(node['len']):
    <%
      if sym_call_num >= len(sym_calls):
        break
      else:
        f = node['funcs'][int(sym_calls[sym_call_num]['data'])]
        sym_call_num += 1
    %>
    call_${f}(ss);
    % endfor
    % endif
    % endfor

    std::cout << (*ss).str();
}
