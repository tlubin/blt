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

  private:
    int* a;
    unsigned cur;
    unsigned sz;
    const int invalidMarker;
    void resize();
};

#endif
