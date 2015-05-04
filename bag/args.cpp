#include "args.hpp" 
#include <cstdlib>
#include <climits>

struct buffer {
  int *buff;
  unsigned cur;
  unsigned sz;
};

static buffer inserted = { (int*)malloc(100*sizeof(int)), 0, 100 };

static void insert(int x) {
  if (inserted.cur >= inserted.sz) {
    inserted.buff = (int*) realloc(inserted.buff, inserted.sz*sizeof(unsigned)*2);
    inserted.sz *= 2;
  }
  inserted.buff[inserted.cur++] = x;
}

/* Random Argument Generators for Bag Functions */
void* args::member_arg(unsigned i) {
  if (!i) {
    int* x = new int[1];
    x[0] = rand() % INT_MAX;
    return (void*) x;
  }
}

void* args::insert_arg(unsigned i) {
  if (!i) {
    int* x = new int[1];
    if ((rand() % 2) && inserted.cur)
      x[0] = inserted.buff[rand() % inserted.cur];
    else { 
      x[0] = rand() % INT_MAX;
      insert(x[0]);
    }
    return (void*) x;
  }
}

void* args::remove_arg(unsigned i) {
  if (!i) {
    int* x = new int[1];
    if ((rand() % 2) && inserted.cur)
      x[0] = inserted.buff[rand() % inserted.cur];
    else
      x[0] = rand() % INT_MAX;
    return (void*) x;
  }
}

