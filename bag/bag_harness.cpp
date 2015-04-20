#include <klee/klee.h>
#include "LilIntBag.hpp"
#include "DynamicIntBag.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>

#define NUM_FUNCS 4
#define SYM_DEPTH 2 
#define CON_DEPTH 250 // XXX fails with greater than 300?

struct funcs {
  int sz;   // number of functions in swarm
  int* fs;  // switch numbers of functions in swarm
};

struct conc_node {
  unsigned isSym;     // symbolic or concrete?
  struct funcs funcs; // subset of functions to run
  unsigned length;    // number of functions to call
  conc_node *next;    // next node
};

conc_node* create_conc_node(unsigned isSym, struct funcs funcs, unsigned length) {
  assert(funcs.sz > 0);
  conc_node *node = new conc_node;
  node->isSym = isSym;
  node->funcs = funcs;
  node->length = length;
  node->next = NULL;
  return node;
}

/* Globals and Helper Function for Prints */
unsigned int output[2*(CON_DEPTH+SYM_DEPTH)];
int outsz = 0;

void print_array(unsigned *a, unsigned len) {
  assert(len < (unsigned) -2);
  char str[len + 2];
  int i;
  for (i = 0; i < len; ++i)
    sprintf(&str[i], "%u", a[i]);
  str[i++] = '\n';
  str[i] = 0;
  printf(str);
}

void call_function(DynamicIntBag* dib, LilIntBag* lib, unsigned int p, int* args) {
  output[outsz++] = p;
  int arg = args[p];
  switch (p) {
    case 0 : {
      bool r1 = dib->member(arg);
      bool r2 = lib->member(arg);
      if (r1 ^ r2) goto FAILURE;
      break; }
    case 1 : {
      dib->insert(arg);
      lib->insert(arg);
      break; }
    case 2 : {
      dib->remove(arg);
      lib->remove(arg);
      break; }
    case 3 : {
      unsigned r1 = dib->get_size();
      unsigned r2 = lib->get_size();
      if (r1 != r2) goto FAILURE;
      break; }
    default :
      break;
  }
  return;

  FAILURE:
  printf("Failed: ");
  print_array(output, outsz);
  klee_assert(0);
}

void clean_mem(conc_node* trace) {
  conc_node *prev_cur;
  while (trace) {
    prev_cur = trace;
    trace = trace-> next;
    delete[] prev_cur->funcs.fs;
    delete prev_cur;
  }
}

void sym_explore(conc_node *node, DynamicIntBag* dib, LilIntBag* lib) {
  unsigned sym_idxs[node->length];
  int args[NUM_FUNCS];
  klee_make_symbolic(&sym_idxs, sizeof(sym_idxs), "sym_fs");
  //klee_make_symbolic(&args, sizeof(args), "args");

  for (unsigned *p = sym_idxs; p < &sym_idxs[node->length]; ++p) {
    // XXX randomly generates arguments for all functions every time?
    for (int k = 0; k < NUM_FUNCS; k++)
      args[k] = rand() % INT_MAX;
    klee_assume(*p < node->funcs.sz);
    call_function(dib, lib, node->funcs.fs[*p], args);
  }
}

void explore(conc_node *trace) {
  conc_node *cur = trace;
  DynamicIntBag* dib = new DynamicIntBag();
  LilIntBag* lib = new LilIntBag();
  int cargs[NUM_FUNCS]; // concrete argument array

  while (cur) {
    if (cur->isSym) {
      // symbolic exploration
      sym_explore(cur, dib, lib);
    } else {
      // concrete execution 
      for (int j = 0; j < cur->length; j++) {
        unsigned int r = rand() % (cur->funcs.sz);
        // XXX randomly generates arguments for all functions every time?
        for (int k = 0; k < NUM_FUNCS; k++)
          cargs[k] = rand() % INT_MAX;
        call_function(dib, lib, cur->funcs.fs[r], cargs);
      }
    }
    cur = cur->next;
  }
  clean_mem(trace);
  delete dib;
  delete lib;
}

// XXX how to test more than one "swarm" after sym_funcs terminate?
// run into same KLEE explosion problem?
conc_node* defaultTrace() {
  funcs hd_funcs;
  hd_funcs.sz = 1;
  hd_funcs.fs = new int[1];
  hd_funcs.fs[0] = 1;
  conc_node *hd = create_conc_node(0, hd_funcs, CON_DEPTH);

  funcs sym_funcs;
  sym_funcs.sz = 3;
  sym_funcs.fs = new int[3];
  sym_funcs.fs[0] = 0;
  sym_funcs.fs[1] = 2;
  sym_funcs.fs[2] = 3;
  conc_node *sym = create_conc_node(1, sym_funcs, SYM_DEPTH);

  funcs hd2_funcs;
  hd2_funcs.sz = 3;
  hd2_funcs.fs = new int[3];
  hd2_funcs.fs[0] = 0;
  hd2_funcs.fs[1] = 2;
  hd2_funcs.fs[2] = 3;  
  conc_node *hd2 = create_conc_node(0, hd2_funcs, CON_DEPTH);

  funcs sym2_funcs;
  sym2_funcs.sz = 3;
  sym2_funcs.fs = new int[3];
  sym2_funcs.fs[0] = 0;
  sym2_funcs.fs[1] = 2;
  sym2_funcs.fs[2] = 3;
  conc_node *sym2 = create_conc_node(1, sym2_funcs, SYM_DEPTH);


  hd->next = sym;
  sym->next = hd2;
  hd2->next = sym2;
  return hd;
}

int main() {
  conc_node *single_trace = defaultTrace();
  explore(single_trace);
  print_array(output, outsz);
}
