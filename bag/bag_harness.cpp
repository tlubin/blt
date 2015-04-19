#include <klee/klee.h>
#include "LilIntBag.hpp"
#include "DynamicIntBag.hpp"
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


void call_function(unsigned int p, void* args) {
  // TODO deal with arguments? 
  switch (p) {
    case 0 : {
      bool r1 = DynamicIntBag::member();
      bool r2 = LilIntBag::member();
      if (r1 ^ r2) goto FAILURE;
      break; }
    case 1 : {
      DynamicIntBag::insert();
      LilIntBag::insert();
      break; }
    case 2 : {
      DynamicIntBag::remove();
      LilIntBag::remove();
      break; }
    case 3 : {
      unsigned r1 = DynamicIntBag::get_size();
      unsigned r2 = LilIntBag::get_size();
      if (r1 != r2) goto FAILURE;
      break; }
    case 4 : {
      unsigned r1 = DynamicIntBag::to_array();
      unsigned r2 = LilIntBag::to_array();
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

int main() {
  unsigned int output[ITERS*(CON_DEPTH+SYM_DEPTH)];
  int cur = 0;
  
  // symbolic functions
  unsigned int fs[SYM_DEPTH];
  //TODO symbolic arguments
  void* sym_args;
  klee_make_symbolic(&sym_args, sizeof(sym_args), "arguments");
  klee_make_symbolic(&fs, sizeof(fs), "fs");
  
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
    cur = 0;
    //printf("swarm %d\n", swarm);
   
    // repeat conc-sym-conc-sym ITERS many times
    for (int i = 0; i < ITERS; i++) {
      // concrete execution 
      for (int j = 0; j < CON_DEPTH; j++) {
        if (sets[swarm].sz) {
          unsigned int r = rand() % (sets[swarm].sz);
          output[cur++] = r;
          // TODO generate arguments
          call_function(sets[swarm].fs[r], args);
        }
      }
      
      // symbolic exploration
      unsigned int *p;
      for (p = fs; p < &fs[SYM_DEPTH]; ++p) {
        klee_assume (*p < NUM_FUNCS);
        output[cur++] = *p;
        call_function(*p, sym_args);
      }
    }
    // trace explored
    print_array(output, cur);
    
    // clean up memory once done with swarm
    delete[] sets[swarm].fs;
  }
  delete[] sets;
}

