#include <klee/klee.h>
#include "new_calc.h"
#include "old_calc.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>

#define SYM_DEPTH 2
#define CON_DEPTH 3 
#define NUM_FUNCS 5 
#define ITERS 5 
#define NUM_SWARMS (1U<<NUM_FUNCS);

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

int main() {
  unsigned int output[ITERS*(CON_DEPTH+SYM_DEPTH)];
  int cur = 0;
  
  // symbolic functions
  unsigned int fs[SYM_DEPTH];
  klee_make_symbolic(&fs, sizeof(fs), "fs");
  
  // swarm function sets
  int i_max = NUM_SWARMS;
  funcs* sets = new funcs[i_max];
  for (int i = 0; i < i_max; ++i) {
    sets[i].fs = new int[NUM_FUNCS];
    sets[i].sz = 0;
    // fill in funcs of set and set size
    for (int x = i, j = 0; x; x >>= 1, ++j) {
      if (x & 1) {
        sets[i].fs[sets[i].sz] = j;
        sets[i].sz++;
      }
    }
  }
  
  for (int swarm = 0; swarm < i_max; swarm++) {
    cur = 0;
    // printf("swarm %d\n", swarm);
    old_calc::init_pressed();
    new_calc::init_pressed();
   
    // repeat conc-sym-conc-sym ITERS many times
    for (int i = 0; i < ITERS; i++) {
      // concrete execution 
      for (int j = 0; j < CON_DEPTH; j++) {
        if (sets[swarm].sz) {
          unsigned int r = rand() % (sets[swarm].sz);
          output[cur++] = r;
          call_function(sets[swarm].fs[r]);
        }
      }
      
      // symbolic exploration
      unsigned int *p;
      for (p = fs; p < &fs[SYM_DEPTH]; ++p) {
        klee_assume (*p < NUM_FUNCS);
        output[cur++] = *p;
        call_function(*p);
      }
    }
    // trace explored
    print_array(output, cur);
  }
}
