#include <klee/klee.h>
#include "LilIntBag.hpp"
#include "DynamicIntBag.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>

#define SYM_DEPTH 2
#define CON_DEPTH 100 
#define NUM_FUNCS 4
#define ITERS 1
#define NUM_SWARMS (1U<<NUM_FUNCS);

struct funcs {
  int sz;   // number of functions in swarm
  int* fs;  // switch numbers of functions in swarm
};

struct conc_node {
  // symbolic or concrete?
  unsigned isSym;

  // subset of functions to run
  struct funcs funcs;

  // number of functions to call
  unsigned length;

  // next node
  conc_node *next;
};

struct conc_node* create_conc_node(unsigned isSym, struct funcs funcs,
				   unsigned length) {
  assert(funcs.sz > 0);
  conc_node *node = new conc_node;
  node->isSym = isSym;
  node->funcs = funcs;
  node->length = length;
  node->next = NULL;
  return node;
}


unsigned int output[ITERS*(CON_DEPTH+SYM_DEPTH)];
int cur = 0;

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
  output[cur++] = p;
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
  printf("Failed on %d\n", p);
  klee_assert(0);
}

void sym_explore(conc_node *node, DynamicIntBag* dib, LilIntBag* lib) {
  unsigned sym_idxs[node->length];
  int args[NUM_FUNCS];
  klee_make_symbolic(&sym_idxs, sizeof(sym_idxs), "sym_fs");
  klee_make_symbolic(&args, sizeof(args), "args");

  for (unsigned *p = sym_idxs; p < &sym_idxs[node->length]; ++p) {
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
        for (int k = 0; k < NUM_FUNCS; k++)
          cargs[k] = rand() % INT_MAX;
        call_function(dib, lib, cur->funcs.fs[r], cargs);
      }
    }
    cur = cur->next;
  }
}

conc_node* defaultTrace() {
  struct funcs hd_funcs;
  hd_funcs.sz = 2;
  hd_funcs.fs = new int[2];
  hd_funcs.fs[0] = 0;
  hd_funcs.fs[1] = 1;  
  conc_node *hd = create_conc_node(0, hd_funcs, 10);

  struct funcs sym_funcs;
  sym_funcs.sz = 2;
  sym_funcs.fs = new int[2];
  sym_funcs.fs[0] = 3;
  sym_funcs.fs[1] = 2;
  conc_node *sym = create_conc_node(1, sym_funcs, 2);

  hd->next = sym;
  return hd;
}

int main() {
  conc_node *single_trace = defaultTrace();
  explore(single_trace);
}
