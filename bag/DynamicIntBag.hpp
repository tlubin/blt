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
    bool pre_member();
    bool pre_insert();
    bool post_member();
    bool post_insert();

  private:
    IntBag* bag;
    const unsigned threshold;
    bool switched;
    void switch_bag();
};

#endif
