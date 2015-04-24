#include <cstdlib>
#include <climits>

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

/* Random Argument Generators for Bag Functions */
void* member_arg() {
  return (void*) rand() % INT_MAX;
}

void* insert_arg() {
  if ((rand() % 2) && inserted.cur)
    return = inserted.buff[rand() % inserted.cur];
  else { 
    int arg = rand() % INT_MAX;
    insert(arg);
    return (void*) arg;
  }
}

void* remove_arg() {
  if ((rand() % 2) && inserted.cur)
    return = inserted.buff[rand() % inserted.cur];
  else
    return (void*) rand() % INT_MAX;
}

