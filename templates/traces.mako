% for t in traces:
void trace${loop.index}() {
  ${class1}* v1 = new ${class1}();
  ${class2}* v2 = new ${class2}();

  % for node in t:
  % if node['symbolic_trace']== 'true':
  for (int i = 0; i < ${node['len']}; ++i) {
    unsigned idx${loop.index};
    klee_make_symbolic(&idx${loop.index}, sizeof(idx${loop.index}), "idx${loop.index}");
    klee_assume(idx${loop.index} < ${len(node['funcs'])});
    switch (idx${loop.index}) {
    % for f in node['funcs']:
    <% 
    func = [func for func in funcs if func['name']==f][0]
    %>
      case ${loop.index}: {
      % if 'pre' in func:
        klee_assume(v1->${func['pre']}());
        klee_assume(v2->${func['pre']}());
        if (v1->${func['pre']}() != v1->${func['pre']}())
          assert(0);
      % endif
        call_${f}(v1, v2, ${node['symbolic_args']});
      % if 'post' in func:
        assert(${func['post']}());
      % endif
        break;
      }
    % endfor
    }
  }
  % else:
  % for f in node['calls']:
  <% 
  func = [func for func in funcs if func['name']==f][0]
  %>
  % if 'pre' in func:
  klee_assume(v1->${func['pre']}());
  klee_assume(v2->${func['pre']}());
  if (v1->${func['pre']}() != v1->${func['pre']}())
    assert(0);
  % endif
  call_${f}(v1, v2, ${node['symbolic_args']});  
  % if 'post' in func:
  assert(v1->${func['post']}());
  assert(v2->${func['post']}());
  % endif
  % endfor
  % endif
  % endfor
}

% endfor
