#include <klee/klee.h>
#include "Trace.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <unistd.h>
#include <sys/wait.h>

#include "LilIntBag.hpp"
#include "DynamicIntBag.hpp"
#include "args.hpp"

#define NUM_FUNCS 4
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

void f0(DynamicIntBag* new_impl, LilIntBag* old_impl, int is_sym) { 
  int arg0;

  if (is_sym) {
    klee_make_symbolic(&arg0, sizeof(arg0),"arg0");
  }
  else {
    arg0 = *(int*)args::member_arg(0);
  }
  if (new_impl->member(arg0) != old_impl->member(arg0)) failure();
}

void f1(DynamicIntBag* new_impl, LilIntBag* old_impl, int is_sym) { 
  int arg0;

  if (is_sym) {
    klee_make_symbolic(&arg0, sizeof(arg0),"arg0");
  }
  else {
    arg0 = *(int*)args::insert_arg(0);
  }
  new_impl->insert(arg0);
  old_impl->insert(arg0);
}

void f2(DynamicIntBag* new_impl, LilIntBag* old_impl, int is_sym) { 
  int arg0;

  if (is_sym) {
    klee_make_symbolic(&arg0, sizeof(arg0),"arg0");
  }
  else {
    arg0 = *(int*)args::remove_arg(0);
  }
  new_impl->remove(arg0);
  old_impl->remove(arg0);
}

void f3(DynamicIntBag* new_impl, LilIntBag* old_impl, int is_sym) { 
  
  
  
  if (new_impl->get_size() != old_impl->get_size()) failure();
}


void call_func(DynamicIntBag* new_impl, LilIntBag* old_impl, unsigned int p, int is_sym) {
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
    default :
      break;
  }
  return;
}

void sym_explore(conc_node *node, DynamicIntBag* new_impl, LilIntBag* old_impl) {
  unsigned sym_idxs[node->length];
  klee_make_symbolic(&sym_idxs, sizeof(sym_idxs), "sym_fs");

  for (unsigned *p = sym_idxs; p < &sym_idxs[node->length]; ++p) {
    klee_assume(*p < node->funcs.sz);
    call_func(new_impl, old_impl, node->funcs.fs[*p], 1);
  }
}

void explore(conc_node *trace) {
  conc_node *cur = trace;
  DynamicIntBag* new_impl = new DynamicIntBag();
  LilIntBag* old_impl = new LilIntBag();

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
