#include <klee/klee.h>
#include "new_calc.h"
#include "old_calc.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <unistd.h>
#include <sys/wait.h>

#define SYM_DEPTH 1
#define CON_DEPTH 10
#define NUM_FUNCS 5 
#define ITERS 1
#define NUM_SWARMS 3 //(1U<<NUM_FUNCS)

struct funcs {
  int sz;
  int* fs;
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


void call_function(unsigned int p) {
  switch (p) {
    case 0 :
      old_calc::zero_pressed();
      new_calc::zero_pressed();
      break;
    case 1 :
      old_calc::one_pressed();
      new_calc::one_pressed();
      break;
    case 2 :
      old_calc::plus_pressed();
      new_calc::plus_pressed();
      break;
    case 3 :
      old_calc::mult_pressed();
      new_calc::mult_pressed();
      break;
    case 4 :
    {
      int old_r = old_calc::eval_pressed();
      int new_r = new_calc::eval_pressed();
      if (old_r != new_r) goto FAILURE;
      break;
    }
    default :
      break;
  }
  return;

  FAILURE:
  klee_assert(0);
}

void sym_explore(conc_node *node) {
  unsigned sym_idxs[node->length];
  klee_make_symbolic(&sym_idxs, sizeof(sym_idxs), "sym_fs");

  for (unsigned *p = sym_idxs; p < &sym_idxs[node->length]; ++p) {
    klee_assume(*p < node->funcs.sz);
    call_function(node->funcs.fs[*p]);
  }
}

void explore(conc_node *trace) {
  // TODO: this should be specified in the trace...
  old_calc::init_pressed();
  new_calc::init_pressed();

  conc_node *cur = trace;
  while (cur) {
    if (cur->isSym) {
      // symbolic exploration
      sym_explore(cur);
    } else {
      // concrete execution 
      for (int j = 0; j < cur->length; j++) {
	  unsigned int r = rand() % (cur->funcs.sz);
	  call_function(cur->funcs.fs[r]);
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
  sym_funcs.fs[0] = 4;
  sym_funcs.fs[1] = 3;
  conc_node *sym = create_conc_node(1, sym_funcs, 2);

  hd->next = sym;
  return hd;
}

int main() {
  //  unsigned int output[ITERS*(CON_DEPTH+SYM_DEPTH)];
  //  int cur = 0;
  
  // swarm function sets
  /*  int i_max = NUM_SWARMS;
  funcs* sets = new funcs[i_max];
  for (int i = 0; i < i_max; ++i) {
    sets[i].fs = new int[NUM_FUNCS];
    sets[i].sz = 0;
    for (int x = i, j = 0; x; x >>= 1, ++j) {
      if (x & 1) {
        sets[i].fs[sets[i].sz] = j;
        sets[i].sz++;
      }
    }
    }*/

  conc_node *single_trace = defaultTrace();
  explore(single_trace);
 
  // do exploration
  /*  for (int swarm = 0; swarm < i_max; swarm++) {
    int pid = fork();
    if (pid == 0) {
      explore(sets[swarm], swarm);
      exit(0);
    }
    waitpid(pid, 0, 0);
    }*/
}
