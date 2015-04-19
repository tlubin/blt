#ifndef _xBIG_INT_BAG_HPP_
#define _xBIG_INT_BAG_HPP_

#include "IntBag.hpp"
#include "BinaryTree.hpp"

class BigIntBag : public IntBag {
  public:
    BigIntBag() {}
    ~BigIntBag() {}
    bool member(int x) { return bt.search(x); }
    void insert(int x) { bt.add(x); }
    void remove(int x) { bt.drop(x); }
    unsigned get_size() { return bt.get_size(); }
    unsigned to_array(int*& dest) { dest = 0; return 0; }

  private:
    BinaryTree bt; 
};

#endif
