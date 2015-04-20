#include "Trace.hpp"
#include <cstdio>
#include <cassert>

Trace::Trace(int c, int s) : 
  con_depth(c), sym_depth(s) { 
}

void Trace::clean_mem(conc_node* trace) {
  conc_node *prev_cur;
  while (trace) {
    prev_cur = trace;
    trace = trace-> next;
    delete[] prev_cur->funcs.fs;
    delete prev_cur;
  }
}

conc_node* Trace::create_conc_node(unsigned isSym, struct funcs funcs, unsigned length) {
  assert(funcs.sz > 0);
  conc_node *node = new conc_node;
  node->isSym = isSym;
  node->funcs = funcs;
  node->length = length;
  node->next = NULL;
  return node;
}

conc_node* Trace::trace1() {
  funcs hd_funcs;
  hd_funcs.sz = 1;
  hd_funcs.fs = new int[1];
  hd_funcs.fs[0] = 1;
  conc_node *hd = create_conc_node(0, hd_funcs, con_depth);

  funcs sym_funcs;
  sym_funcs.sz = 2;
  sym_funcs.fs = new int[2];
  sym_funcs.fs[0] = 0;
  sym_funcs.fs[1] = 2;
  conc_node *sym = create_conc_node(1, sym_funcs, sym_depth);

  funcs hd2_funcs;
  hd2_funcs.sz = 2;
  hd2_funcs.fs = new int[2];
  hd2_funcs.fs[0] = 0;
  hd2_funcs.fs[1] = 2;
  conc_node *hd2 = create_conc_node(0, hd2_funcs, con_depth);

  funcs sym2_funcs;
  sym2_funcs.sz = 2;
  sym2_funcs.fs = new int[2];
  sym2_funcs.fs[0] = 0;
  sym2_funcs.fs[1] = 2;
  conc_node *sym2 = create_conc_node(1, sym2_funcs, sym_depth);

  hd->next = sym;
  sym->next = hd2;
  hd2->next = sym2;
  return hd;
}

conc_node* Trace::trace2() {
  funcs hd_funcs;
  hd_funcs.sz = 1;
  hd_funcs.fs = new int[1];
  hd_funcs.fs[0] = 1;
  conc_node *hd = create_conc_node(0, hd_funcs, con_depth);

  funcs sym_funcs;
  sym_funcs.sz = 3;
  sym_funcs.fs = new int[3];
  sym_funcs.fs[0] = 0;
  sym_funcs.fs[1] = 2;
  sym_funcs.fs[2] = 3;
  conc_node *sym = create_conc_node(1, sym_funcs, sym_depth);

  hd->next = sym;
  return hd;
}
