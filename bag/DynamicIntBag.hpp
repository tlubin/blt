#ifndef _xDYNAMIC_INT_BAG_HPP_
#define _xDYNAMIC_INT_BAG_HPP_

#include "IntBag.hpp"

class DynamicIntBag : public IntBag {
  public:
    DynamicIntBag();
    ~DynamicIntBag();
    bool member(int);
    void insert(int);
    void remove(int);

  private:
    // This can first point to a LilIntBag and then switch to a BigIntBag
    IntBag* bag; 
    // ...
};

#endif
