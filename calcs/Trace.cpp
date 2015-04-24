#include "Trace.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>

Trace::Trace(unsigned c, unsigned s, unsigned nf) : 
  con_depth(c), sym_depth(s), num_funcs(nf) { 
  i_max = 1U << num_funcs;
  sets = new funcs[i_max];
  for (int i = 0; i < i_max; ++i) {
    sets[i].fs = new int[num_funcs];
    sets[i].sz = 0;
    for (int x = i, j = 0; x; x >>= 1, ++j) {
      if (x & 1) {
        sets[i].fs[sets[i].sz] = j;
        sets[i].sz++;
      }
    }
  }
}

Trace::~Trace() {
  delete[] sets;
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
  // must init
  funcs hd_funcs;
  hd_funcs.sz = 1;
  hd_funcs.fs = new int[1];
  hd_funcs.fs[0] = 0;
  conc_node *hd = create_conc_node(0, hd_funcs, 1);

  // type some calculation (could be invalid) 
  // symbolic trace of length 10
  funcs sym_funcs;
  sym_funcs.sz = 4;
  sym_funcs.fs = new int[4];
  sym_funcs.fs[0] = 1;
  sym_funcs.fs[1] = 2;
  sym_funcs.fs[2] = 3;
  sym_funcs.fs[2] = 4;
  conc_node *sym = create_conc_node(1, sym_funcs, 10);

  // evaluate
  funcs hd2_funcs;
  hd2_funcs.sz = 1;
  hd2_funcs.fs = new int[1];
  hd2_funcs.fs[0] = 5;
  conc_node *hd2 = create_conc_node(0, hd2_funcs, 1);

  hd->next = sym;
  sym->next = hd2;
  return hd;
}

conc_node* Trace::random(unsigned con_depth, unsigned sym_depth) {
  unsigned r = rand() % i_max;
  conc_node *hd = create_conc_node(0, sets[r], con_depth);

  unsigned r2 = rand() % i_max;
  conc_node *sym = create_conc_node(1, sets[r2], sym_depth);

  hd->next = sym;
  return hd;
}
