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
  printf("Failed on %d\n", p);
  klee_assert(0);
}

void explore(funcs swarm, int i) {
  printf("swarm %d*\n", i);
  // symbolic functions
  unsigned int fs[SYM_DEPTH];
  klee_make_symbolic(&fs, sizeof(fs), "fs");

  old_calc::init_pressed();
  new_calc::init_pressed();
   
  // repeat conc-sym-conc-sym ITERS many times
  for (int i = 0; i < ITERS; i++) {
    // concrete execution 
    for (int j = 0; j < CON_DEPTH; j++) {
      if (swarm.sz) {
	unsigned int r = rand() % (swarm.sz);
	call_function(swarm.fs[r]);
      }
    }
      
    // symbolic exploration
    unsigned int *p;
    for (p = fs; p < &fs[SYM_DEPTH]; ++p) {
      klee_assume (*p < NUM_FUNCS);
      call_function(*p);
    }
  }
}

int main() {
  //  unsigned int output[ITERS*(CON_DEPTH+SYM_DEPTH)];
  //  int cur = 0;
  
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
  for (int swarm = 0; swarm < i_max; swarm++) {
    int pid = fork();
    if (pid == 0) {
      explore(sets[swarm], swarm);
      exit(0);
    }
    waitpid(pid, 0, 0);
  }
}
