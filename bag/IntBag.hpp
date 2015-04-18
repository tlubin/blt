#ifndef _xINT_BAG_HPP_
#define _xINT_BAG_HPP_

class IntBag {
  public:
    virtual bool member(int) = 0;
    virtual void insert(int) = 0;
    virtual void remove(int) = 0;
    virtual unsigned get_size() = 0;
    virtual unsigned to_array(int*&) = 0;
};

#endif
