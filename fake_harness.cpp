#include <klee/klee.h>
#include <cstdio>
#include <cassert>

int old_x = 0, old_y = 0, old_z = 0;
int new_x = 0, new_y = 0, new_z = 0;

int old_f1() {
  return ++old_x;
}

int old_f2() {
  return ++old_y;
}

int old_f3() {
  return ++old_z;
}

int new_f1() {
  return ++new_x;
}

int new_f2() {
  return ++new_y;
}

int new_f3() {
  return ++new_z;
}

int new_g() {
  return --new_x;
}

int main() {
  int ns[5];
  klee_make_symbolic(&ns, sizeof(ns), "ns");

  int *p;
  int d = 0;
  for (p = ns; p < &ns[5]; ++p) {
    d = d * 10;
    int x = *p % 4;
    if (x == 0) {
      if (old_f1() != new_f1()) goto FAILURE;
      d += 1;
    } else if (x == 1) {
      if (old_f2() != new_f2()) goto FAILURE;
      d += 2 ;
    } else if (x == 2){
      if (old_f3() != new_f3()) goto FAILURE;
      d += 3;
    } else {
      new_g();
      d += 4;
    }      
  }

  printf("%d\n", d);
  return 0;

  FAILURE:
  printf("%d\n", d);
  assert(0);
}
