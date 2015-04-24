#include <klee/klee.h>
#include "Trace.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <unistd.h>
#include <sys/wait.h>

#include "old_calc.h"
#include "new_calc.h"
#include "args.hpp"

#define NUM_FUNCS 6
// defined in traces file
#define NUM_TRACES 1

static struct output {
  unsigned *buff;
  unsigned cur;
  unsigned sz;
} output;

void init_output() {
  output.buff = (unsigned*) malloc(100*sizeof(int)); 
  output.cur = 0;
  output.sz = 100;
}

static void output_add(int x) {
  if (output.cur >= output.sz) {
    output.buff = (unsigned*) realloc(output.buff, output.sz*sizeof(unsigned)*2);
    output.sz *= 2;
  }
  output.buff[output.cur++] = x;
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

void failure() {
  printf("Failed: ");
  print_array(output.buff, output.cur);
  klee_assert(0);
}

void f0(new_calc* new_impl, old_calc* old_impl, int is_sym) { 
  
  
  
  new_impl->init_pressed();
old_impl->init_pressed();

}

void f1(new_calc* new_impl, old_calc* old_impl, int is_sym) { 
  
  
  
  new_impl->zero_pressed();
old_impl->zero_pressed();

}

void f2(new_calc* new_impl, old_calc* old_impl, int is_sym) { 
  
  
  
  new_impl->one_pressed();
old_impl->one_pressed();

}

void f3(new_calc* new_impl, old_calc* old_impl, int is_sym) { 
  
  
  
  new_impl->plus_pressed();
old_impl->plus_pressed();

}

void f4(new_calc* new_impl, old_calc* old_impl, int is_sym) { 
  
  
  
  new_impl->mult_pressed();
old_impl->mult_pressed();

}

void f5(new_calc* new_impl, old_calc* old_impl, int is_sym) { 
  
  
  
  new_impl->eval_pressed();
old_impl->eval_pressed();

}


void call_func(new_calc* new_impl, old_calc* old_impl, unsigned int p, int is_sym) {
  output_add(p);
  switch (p) {
    case 0 : {
      f0(new_impl, old_impl, is_sym);
      break; }
    case 1 : {
      f1(new_impl, old_impl, is_sym);
      break; }
    case 2 : {
      f2(new_impl, old_impl, is_sym);
      break; }
    case 3 : {
      f3(new_impl, old_impl, is_sym);
      break; }
    case 4 : {
      f4(new_impl, old_impl, is_sym);
      break; }
    case 5 : {
      f5(new_impl, old_impl, is_sym);
      break; }
    default :
      break;
  }
  return;
}

void sym_explore(conc_node *node, new_calc* new_impl, old_calc* old_impl) {
  unsigned sym_idxs[node->length];
  klee_make_symbolic(&sym_idxs, sizeof(sym_idxs), "sym_fs");

  for (unsigned *p = sym_idxs; p < &sym_idxs[node->length]; ++p) {
    klee_assume(*p < node->funcs.sz);
    call_func(new_impl, old_impl, node->funcs.fs[*p], 1);
  }
}

void explore(conc_node *trace) {
  conc_node *cur = trace;
  new_calc* new_impl = new new_calc();
  old_calc* old_impl = new old_calc();

  while (cur) {
    if (cur->isSym) {
      // symbolic exploration
      sym_explore(cur, new_impl, old_impl);
    } else {
      // concrete execution 
      for (int j = 0; j < cur->length; j++) {
        unsigned int r = rand() % (cur->funcs.sz);
        call_func(new_impl, old_impl, cur->funcs.fs[r], 0);
      }
    }
    cur = cur->next;
  }
}

int main() {
  init_output();
  Trace trace(1, 1, NUM_FUNCS);
  conc_node** traces = new conc_node*[NUM_TRACES];
  traces[0] = trace.trace1();

  pid_t pid;
  for (int i = 0; i < NUM_TRACES; ++i) {
    pid = fork();
    if (pid == 0) {
      explore(traces[i]);
      print_array(output.buff, output.cur);
      exit(0);
    }
    waitpid(pid, 0, 0);
  }

  for (int i = 0; i < NUM_TRACES; ++i)
    trace.clean_mem(traces[i]);
  delete[] traces;
}
