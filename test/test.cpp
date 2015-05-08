#include <cstring>
#include <cassert>
#include "test.hpp"

struct hidden *glob = NULL;


void Test::set(struct hidden *h, unsigned x) {
  h->foo = x;
}

void Test::inc(struct hidden *h) {
  h->foo += 1;
}

unsigned Test::get(struct hidden *h) {
  if (h->foo == 42)
    assert(0);
  return h->foo;
}

//////////// ARGS //////////////////

void* args::arg_inc(unsigned i) {
  if (!glob) {
    glob = new struct hidden;
    glob->foo = 0;
  }
  return &glob;
}

void* args::arg_get(unsigned i) {
  return &glob;
}


void* args::arg_set(unsigned i) {
  if (!glob) {
    glob = new struct hidden;
    glob->foo = 0;
  }
  if (i == 0) {
    return &glob;
  }
  else {
    unsigned *x = new unsigned;
    *x = 42;
    return x;
  }
}
