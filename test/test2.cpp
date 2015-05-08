#include <cstring>
#include <cassert>
#include "test2.hpp"

struct hidden *glob = NULL;

Test2::Test2() {
  glob = new struct hidden;
  glob->foo = 0;
}

void Test2::set(unsigned x) {
  glob->foo = x;
}

void Test2::inc() {
  glob->foo += 1;
}

unsigned Test2::get() {
  if (glob->foo == 12345)
    assert(0);
  return glob->foo;
}
