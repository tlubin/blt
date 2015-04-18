#ifndef _xDYNAMIC_INT_BAG_HPP_
#define _xDYNAMIC_INT_BAG_HPP_

#include "IntBag.hpp"

class DynamicIntBag : public IntBag {
  public:
    DynamicIntBag();
    DynamicIntBag(int);
    ~DynamicIntBag();
    bool member(int);
    void insert(int);
    void remove(int);
    unsigned get_size();
    unsigned to_array(int*&);

  private:
    IntBag* bag;
    const unsigned threshold;
    bool switched;
    void switch_bag();
};

#endif
