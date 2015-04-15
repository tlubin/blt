#include <klee/klee.h>
#include "new_calc.h"
#include "old_calc.h"
#include <cstdio>
#include <cassert>

#define TRACE_DEPTH 2

typedef int (*int_func)();

int old_x = 0, old_y = 0, old_z = 0;
int new_x = 0, new_y = 0, new_z = 0;

int_func old_fs[3] = { &old_f1, &old_f2, &old_f3 };
int_func new_fs[3] = { &new_f1, &new_f2, &new_f3 };

int main() {
  unsigned int fs[TRACE_DEPTH];
  klee_make_symbolic(&fs, sizeof(fs), "fs");

  unsigned int o = 0;  // stupid hack for recording interleavings
  unsigned int *p;
  for (p = fs; p < &fs[TRACE_DEPTH]; ++p) {
    o *= 10;

    //unsigned int x = *p % 3;  // this doesn't work as well
    unsigned int x = *p;
    klee_assume (x < 3);
    o += x + 1;
    int old_r = old_fs[x]();
    int new_r = new_fs[x]();
    // uncomment to short-circuit
    // if (old_r != new_r) goto FAILURE;
  }

  printf("%d\n", o);
  return 0;

  FAILURE:
  printf("%d\n", o);
  klee_assert(0);
