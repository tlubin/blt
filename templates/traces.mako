% for t in traces:
void trace${loop.index}() {
  std::stringstream* ss = new std::stringstream();
  ${class1}* v1 = new ${class1}();
  ${class2}* v2 = new ${class2}();

  % for node in t:
  % if node['symbolic_trace']== 'true':
  for (int i = 0; i < ${node['len']}; ++i) {
    unsigned n${loop.index};
    klee_make_symbolic(&n${loop.index}, sizeof(n${loop.index}), "n${loop.index}");
    klee_assume(n${loop.index} < ${len(node['funcs'])});
    switch (n${loop.index}) {
    % for f in node['funcs']:
      case ${loop.index}:
        call_${f}(v1, v2, ${node['symbolic_args']}, ss);
        break;
    % endfor
    }
  }
  % else:
  % for f in node['calls']:
  call_${f}(v1, v2, ${node['symbolic_args']}, ss);  
  % endfor
  % endif
  % endfor
}

% endfor
