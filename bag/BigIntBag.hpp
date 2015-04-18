#ifndef _xBIG_INT_BAG_HPP_
#define _xBIG_INT_BAG_HPP_

#include "IntBag.hpp"

class BigIntBag : public IntBag {
  public:
    BigIntBag();
    ~BigIntBag();
    bool member(int);
    void insert(int);
    void remove(int);
    unsigned get_size();
    unsigned to_array(int*&);

  private:
    // ...
};

#endif
