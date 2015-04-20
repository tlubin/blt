#include <klee/klee.h>
#include "LilIntBag.hpp"
#include "DynamicIntBag.hpp"
#include "Trace.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_FUNCS 4
#define SYM_DEPTH 3
#define CON_DEPTH 1000

/* Globals and Helper Function for Prints */
unsigned int output[2*(CON_DEPTH+SYM_DEPTH)];
int outsz = 0;

static struct inserted {
  int *buff;
  unsigned cur;
  unsigned sz;
} inserted;

void init() {
  inserted.buff = (int*) malloc(100*sizeof(int)); 
  inserted.cur = 0;
  inserted.sz = 100;
}

static void insert(int x) {
  if (inserted.cur >= inserted.sz) {
    inserted.buff = (int*) realloc(inserted.buff, inserted.sz*sizeof(unsigned)*2);
    inserted.sz *= 2;
  }
  inserted.buff[inserted.cur++] = x;
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
      if ((rand() % 2) && inserted.cur)
        arg = inserted.buff[rand() % inserted.cur];
      dib->insert(arg);
      lib->insert(arg);
      insert(arg);
      break; }
    case 2 : {
      if ((rand() % 2) && inserted.cur)
        arg = inserted.buff[rand() % inserted.cur];
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
  printf("Failed: %u, %u\n", dib->get_size(), lib->get_size()); 
  print_array(output, outsz);
  klee_assert(0);
}

void sym_explore(conc_node *node, DynamicIntBag* dib, LilIntBag* lib) {
  unsigned sym_idxs[node->length];
  int args[NUM_FUNCS];
  klee_make_symbolic(&sym_idxs, sizeof(sym_idxs), "sym_fs");
  //klee_make_symbolic(&args, sizeof(args), "args");

  for (unsigned *p = sym_idxs; p < &sym_idxs[node->length]; ++p) {
    // XXX randomly generates arguments, no symbolic arguments
    for (int k = 0; k < NUM_FUNCS; k++)
      args[k] = rand() % INT_MAX;
    klee_assume(*p < node->funcs.sz);
    call_function(dib, lib, node->funcs.fs[*p], args);
  }
}

void explore(conc_node *trace) {
  init();
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
}

int main() {
  Trace trace(CON_DEPTH, SYM_DEPTH);
  conc_node** traces = new conc_node*[2];
  traces[0] = trace.trace1();
  traces[1] = trace.trace2();

  pid_t pid;
  for (int i = 0; i < 2; ++i) {
    pid = fork();
    if (pid == 0) {
      explore(traces[i]);
      print_array(output, outsz);
      exit(0);
    }
    waitpid(pid, 0, 0);
  }

  for (int i = 0; i < 2; ++i)
    trace.clean_mem(traces[i]);
  delete[] traces;
}
