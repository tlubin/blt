#ifndef _xLIL_INT_BAG_HPP_
#define _xLIL_INT_BAG_HPP_

#include "IntBag.hpp"

class LilIntBag : public IntBag {
  public:
    LilIntBag();
    ~LilIntBag();
    bool member(int);
    void insert(int);
    void remove(int);
    unsigned get_size();
    unsigned to_array(int*&);
    bool pre_member();
    bool pre_insert();

  private:
    int* a;
    unsigned cur;
    unsigned sz;
    void resize();
};

#endif
