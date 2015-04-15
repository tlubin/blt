#include <klee/klee.h>
#include "new_calc.h"
#include "old_calc.h"
#include <cstdio>
#include <cassert>

#define TRACE_DEPTH 11

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

int main() {
  unsigned int fs[TRACE_DEPTH];
  unsigned int output[TRACE_DEPTH];
  klee_make_symbolic(&fs, sizeof(fs), "fs");

  unsigned int o = 0;  // stupid hack for recording interleavings
  unsigned int *p;
  old_calc::init_pressed();
  new_calc::init_pressed();
  
  for (p = fs; p < &fs[TRACE_DEPTH]; ++p) {
    klee_assume (*p < 5);
    output[p - fs] = *p;
    switch (*p) {
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
        //assert(old_r == new_r);
        break;
      }
      default :
        break;
    }
  }

  print_array(output, TRACE_DEPTH);
  return 0;

  FAILURE:
  klee_assert(0);
}
