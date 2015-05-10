// TODO: run this to see how many mutants it finds
// g++ rbmanual.cpp mutations/rbtree###.cpp

#include "RBTreeBag.hpp"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <set>

using namespace std;

#define INSERT_PERCENT 50
#define REMOVE_PERCENT 25
#define MEMBER_PERCENT 25

int steps = 100000;
RBTreeBag *bag;
multiset<int> myset;

void insert() {
  int randNum = rand() % 100;
  myset.insert(randNum);
  bag->insert(randNum);
}

void remove() {
  multiset<int>::iterator it;
  unsigned sz = myset.size();
  if (sz > 0) {
    it = myset.begin();
    advance(it, (sz == 1 ? 0 : rand() % (sz - 1)));
    myset.erase(it);
    bag->remove(*it);
  }
}

void member() {
  int randNum = rand() % 100;
  unsigned count = myset.count(randNum);
  assert(count == 0 || bag->member(randNum));
}

int main() {
  bag = new RBTreeBag;

  while (steps--) {
    int op = rand() % 100;
    if (op < INSERT_PERCENT)
      insert();
    else if (op < INSERT_PERCENT + REMOVE_PERCENT)
      remove();
    else
      member();
  }
}
