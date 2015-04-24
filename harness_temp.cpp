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

##FUNCTION_TEMP##
void f#FUNC_NUM#(#NEW_IMPL#* new_impl, #OLD_IMPL#* old_impl, int is_sym) { 
  #DEFINE_ARGS#
  #MAKE_ARGS_SYMBOLIC#
  #MAKE_ARGS_CONCRETE#
  #CHECK_EQUALITY#
}

##END_FUNCTION_TEMP##

void call_func(#NEW_IMPL#* new_impl, #OLD_IMPL#* old_impl, unsigned int p, int is_sym) {
  output_add(p);
  switch (p) {
    ##CASE_TEMP##
    case #FUNC_NUM# : {
      f#FUNC_NUM#(new_impl, old_impl, is_sym);
      break; }
    ##END_CASE_TEMP##
    default :
      break;
  }
  return;
}

void sym_explore(conc_node *node, #NEW_IMPL#* new_impl, #OLD_IMPL#* old_impl) {
  unsigned sym_idxs[node->length];
  klee_make_symbolic(&sym_idxs, sizeof(sym_idxs), "sym_fs");

  for (unsigned *p = sym_idxs; p < &sym_idxs[node->length]; ++p) {
    klee_assume(*p < node->funcs.sz);
    call_func(new_impl, old_impl, node->funcs.fs[*p], 1);
  }
}

void explore(conc_node *trace) {
  conc_node *cur = trace;
  #NEW_IMPL#* new_impl = new #NEW_IMPL#();
  #OLD_IMPL#* old_impl = new #OLD_IMPL#();

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
