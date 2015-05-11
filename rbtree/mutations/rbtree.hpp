/*  CONVENTIONS:  All data structures for red-black trees have the prefix */
/*                "rb_" to prevent name conflicts. */
/*                                                                      */
/*                Function names: Each word in a function name begins with */
/*                a capital letter.  An example funcntion name is  */
/*                CreateRedTree(a,b,c). Furthermore, each function name */
/*                should begin with a capital letter to easily distinguish */
/*                them from variables. */
/*                                                                     */
/*                Variable names: Each word in a variable name begins with */
/*                a capital letter EXCEPT the first letter of the variable */
/*                name.  For example, int newLongInt.  Global variables have */
/*                names beginning with "g".  An example of a global */
/*                variable name is gNewtonsConstant. */

#ifndef _xRB_TREE_HPP_
#define _xRB_TREE_HPP_

typedef struct rb_red_blk_node {
  int key;
  int red; /* if red=0 then the node is black */
  struct rb_red_blk_node* left;
  struct rb_red_blk_node* right;
  struct rb_red_blk_node* parent;
} rb_red_blk_node;


typedef struct rb_red_blk_tree {
  /*  A sentinel is used for root and for nil.  These sentinels are */
  /*  created when RBTreeCreate is caled.  root->left should always */
  /*  point to the node which is the root of the tree.  nil points to a */
  /*  node which should always be black but has aribtrary children and */
  /*  parent and no key or info.  The point of using these sentinels is so */
  /*  that the root and nil nodes do not require special cases in the code */
  rb_red_blk_node* root;             
  rb_red_blk_node* nil;              
} rb_red_blk_tree;

class RBTree {
 public:
  RBTree();

  //rb_red_blk_node * RBTreeInsert(rb_red_blk_tree*, void* key, void* info);
  void RBTreeInsert(int key);

  //void RBDelete(rb_red_blk_tree* , rb_red_blk_node* );
  void RBDelete(int key);

  // TODO: maybe keep Pred and Succ functions?
  //rb_red_blk_node* TreePredecessor(rb_red_blk_tree*,rb_red_blk_node*);
  //rb_red_blk_node* TreeSuccessor(rb_red_blk_tree*,rb_red_blk_node*);

  //rb_red_blk_node* RBExactQuery(rb_red_blk_tree*, void*);
  bool RBMember(int key);
  //stk_stack * RBEnumerate(rb_red_blk_tree* tree,void* low, void* high);
  //void NullFunction(void*);
};

#endif
