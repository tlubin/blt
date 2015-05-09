#ifndef _xRB_TREE_BAG_HPP_
#define _xRB_TREE_BAG_HPP_

#include "rbtree.hpp"

class RBTreeBag {
  public:
    RBTreeBag() {}
    ~RBTreeBag() {}
    bool member(int x) {return tree.RBMember(x);};
    void insert(int x) {tree.RBTreeInsert(x);};
    void remove(int x) {tree.RBDelete(x);};
  private:
    RBTree tree;
};

#endif
