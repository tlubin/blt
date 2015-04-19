#include <klee/klee.h>
#include "LilIntBag.hpp"
#include "DynamicIntBag.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cerrno>
#include <unistd.h>
#include <sys/wait.h>

#define SYM_DEPTH 2
#define CON_DEPTH 3 
#define NUM_FUNCS 4
#define ITERS 1
#define NUM_SWARMS (1U<<NUM_FUNCS);

struct funcs {
  int sz;
  int* fs;
};

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

void explore(funcs swarm, int i) {
  printf("swarm %d*\n", i);
  unsigned int fs[SYM_DEPTH]; // symbolic functions
  int args[NUM_FUNCS];        // symbolic argument array
  klee_make_symbolic(&fs, sizeof(fs), "fs");
  klee_make_symbolic(&args, sizeof(args), "args");

  DynamicIntBag* dib = new DynamicIntBag();
  LilIntBag* lib = new LilIntBag();
  int cargs[NUM_FUNCS];       // concrete argument array

  // repeat conc-sym-conc-sym ITERS many times
  for (int i = 0; i < ITERS; i++) {
    // concrete execution 
    for (int j = 0; j < CON_DEPTH; j++) {
        if (swarm.sz) {
          unsigned int r = rand() % (swarm.sz);
          for (int k = 0; k < NUM_FUNCS; k++)
            cargs[k] = rand() % INT_MAX;
          call_function(dib, lib, swarm.fs[r], cargs);
        }
      }
      
    // symbolic exploration
    unsigned int *p;
    for (p = fs; p < &fs[SYM_DEPTH]; ++p) {
      klee_assume (*p < NUM_FUNCS);
      call_function(dib, lib, *p, args);
    }
  }
  //print_array(output, cur);
}

int main() {
  // swarm function sets
  int i_max = NUM_SWARMS;
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
  }
 
  // do exploration
  pid_t pid;
  for (int swarm = 0; swarm < i_max; swarm++) {
    pid = fork();
    if (pid == 0) {
      explore(sets[swarm], swarm);
      exit(0);
    }
    waitpid(pid, 0, 0);
    cur = 0;
    delete[] sets[swarm].fs;
  }
  // comment out waitpid above and uncomment the following code to fork all swarms at once
  /*while (pid = waitpid(-1, NULL, 0)) {
    if (errno == ECHILD)
      break;
  }*/
  
  // clean up memory once done with swarm
  delete[] sets;
}
