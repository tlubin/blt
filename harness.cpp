#include <klee/klee.h>
#include "Trace.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <unistd.h>
#include <sys/wait.h>

#include "#OLD_HEADER#"
#include "#NEW_HEADER#"
#include "args.hpp"

#define NUM_FUNCS #FUNC_COUNT#
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

// INSTANTIATE TEMPLATE
void f(#NEW_IMPL#* new_impl, #OLD_IMPL#* old_impl, int is_sym) { 
  #DEFINE_ARGS#
  /*
    int arg1;
    char arg2; 
    ...
  */
  
  if (is_sym)
    #MAKE_ARGS_SYMBOLIC#
    /*
      klee_make_symbolic(&arg1, sizeof(arg1), "arg1");
      klee_make_symbolic(&arg2, sizeof(arg2), "arg2");
    */
  else {
    #MAKE_ARGS_CONCRETE#
    /*
      arg1 = ((int*)args::member_arg())[0];
      arg2 = ((int*)args::member_arg())[1];
     */
  }
  #CHECK_EQUALITY#
  /* void return
     new_impl->FUNC(arg1, arg2, ...);
     old_impl->FUNC(arg1, arg2, ...);     
   */

  /* non-void return
     if (new_impl->FUNC(arg1, arg2, ...) != old_impl->FUNC(arg1,...))
         failure();
   */
}


void call_func(DynamicIntBag* dib, LilIntBag* lib, unsigned int p, int is_sym) {
  output_add(p);
  // TODO! TEMPLATE THIS AS WELL
  switch (p) {
    case 0 : {
      f0(dib, lib, is_sym);
      break; }
    case 1 : {
      f1(dib, lib, is_sym);
      break; }
    case 2 : {
      f2(dib, lib, is_sym);
      break; }
    case 3 : {
      f3(dib, lib, is_sym);
      break; }
    default :
      break;
  }
  return;

  FAILURE:
  printf("Failed: ");
  print_array(output.buff, output.cur);
  klee_assert(0);
}

void sym_explore(conc_node *node, DynamicIntBag* dib, LilIntBag* lib) {
  unsigned sym_idxs[node->length];
  klee_make_symbolic(&sym_idxs, sizeof(sym_idxs), "sym_fs");

  for (unsigned *p = sym_idxs; p < &sym_idxs[node->length]; ++p) {
    klee_assume(*p < node->funcs.sz);
    call_func(dib, lib, node->funcs.fs[*p], 1);
  }
}

void explore(conc_node *trace) {
  conc_node *cur = trace;
  DynamicIntBag* dib = new DynamicIntBag();
  LilIntBag* lib = new LilIntBag();

  while (cur) {
    if (cur->isSym) {
      // symbolic exploration
      sym_explore(cur, dib, lib);
    } else {
      // concrete execution 
      for (int j = 0; j < cur->length; j++) {
        unsigned int r = rand() % (cur->funcs.sz);
        call_func(dib, lib, cur->funcs.fs[r], 0);
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
