#include "rbtree.hpp"
#include <cstdlib>
#include <cassert>

rb_red_blk_tree* tree = NULL;


RBTree::RBTree() {
  rb_red_blk_node* temp;

  tree=new rb_red_blk_tree;

      temp=tree->nil= new rb_red_blk_node;
  temp->parent=temp->left=temp->right=temp;
  temp->red=0;
  temp->key=0;
  temp=tree->root= new rb_red_blk_node;
  temp->parent=temp->left=temp->right=tree->nil;
  temp->key=0;
  temp->red=0;

}

int compare(int x, int y) {
  if (x == y)
    return 0;
  else if (x > y)
    return 1;
  else
    return -1;
}


void LeftRotate(rb_red_blk_node* x) {
  rb_red_blk_node* y;
  rb_red_blk_node* nil=tree->nil;

                  
  y=x->right;
  x->right=y->left;

  if (y->left != nil) y->left->parent=x;     
  y->parent=x->parent;   

      if( x == x->parent->left) {
    x->parent->left=y;
  } else {
    x->parent->right=y;
  }
  y->left=x;
  x->parent=y;
}



void RightRotate(rb_red_blk_node* y) {
  rb_red_blk_node* x;
  rb_red_blk_node* nil=tree->nil;

                  
  x=y->left;
  y->left=x->right;

  if (nil != x->right)  x->right->parent=y;   
      x->parent=y->parent;
  if( y == y->parent->left) {
    y->parent->left=x;
  } else {
    y->parent->right=x;
  }
  x->right=y;
  y->parent=x;
}


void TreeInsertHelp(rb_red_blk_node* z) {
    rb_red_blk_node* x;
  rb_red_blk_node* y;
  rb_red_blk_node* nil=tree->nil;
  
  z->left=z->right=nil;
  y=tree->root;
  x=tree->root->left;
  while( x != nil) {
    y=x;
    if (1 == compare(x->key,z->key)) {       x=x->left;
    } else {       x=x->right;
    }
  }
  z->parent=y;
  if ( (y == tree->root) ||
       (1 == compare(y->key,z->key))) {     y->left=z;
  } else {
    y->right=z;
  }
}



void RBTree::RBTreeInsert(int key) {
  rb_red_blk_node * y;
  rb_red_blk_node * x;
  rb_red_blk_node * newNode;

  x=new rb_red_blk_node;
  x->key=key;

  TreeInsertHelp(x);
  newNode=x;
  x->red=1;
  while(x->parent->red) {     if (x->parent == x->parent->parent->left) {
      y=x->parent->parent->right;
      if (y->red) {
	x->parent->red=0;
	y->red=0;
	x->parent->parent->red=1;
	x=x->parent->parent;
      } else {
	if (x == x->parent->right) {
	  x=x->parent;
	  LeftRotate(x);
	}
	x->parent->red=0;
	x->parent->parent->red=1;
	RightRotate(x->parent->parent);
      } 
    } else {       y=x->parent->parent->left;
      if (y->red) {
	x->parent->red=0;
	y->red=0;
	x->parent->parent->red=1;
	x=x->parent->parent;
      } else {
	if (x == x->parent->left) {
	  x=x->parent;
	  RightRotate(x);
	}
	x->parent->red=0;
	x->parent->parent->red=1;
	LeftRotate(x->parent->parent);
      } 
    }
  }
  tree->root->left->red=0;
}


rb_red_blk_node* RBExactQuery(int q) {
  rb_red_blk_node* x=tree->root->left;
  rb_red_blk_node* nil=tree->nil;
  int compVal;
  if (x == nil) return(0);
  compVal= compare(x->key, q);
  while(0 != compVal) {    if (1 == compVal) {       x=x->left;
    } else {
      x=x->right;
    }
    if ( x == nil) return(0);
    compVal=compare(x->key, q);
  }
  return(x);
}

bool RBTree::RBMember(int key) {
  return RBExactQuery(key) != NULL;
}
  



void RBDeleteFixUp(rb_red_blk_node* x) {
  rb_red_blk_node* root=tree->root->left;
  rb_red_blk_node* w;

  while( (!x->red) && (root != x)) {
    if (x == x->parent->left) {
      w=x->parent->right;
      if (w->red) {
	w->red=0;
	x->parent->red=1;
	LeftRotate(x->parent);
	w=x->parent->right;
      }
      if ( (!w->right->red) && (!w->left->red) ) { 
	w->red=1;
	x=x->parent;
      } else {
	if (!w->right->red) {
	  w->left->red=0;
	  w->red=1;
	  RightRotate(w);
	  w=x->parent->right;
	}
	w->red=x->parent->red;
	x->parent->red=0;
	w->right->red=0;
	LeftRotate(x->parent);
	x=root;       }
    } else {       w=x->parent->left;
      if (w->red) {
	w->red=0;
	x->parent->red=1;
	RightRotate(x->parent);
	w=x->parent->left;
      }
      if ( (!w->right->red) && (!w->left->red) ) { 
	w->red=1;
	x=x->parent;
      } else {
	if (!w->left->red) {
	  w->right->red=0;
	  w->red=1;
	  LeftRotate(w);
	  w=x->parent->left;
	}
	w->red=x->parent->red;
	x->parent->red=0;
	w->left->red=0;
	RightRotate(x->parent);
	x=root;       }
    }
  }
  x->red=0;
}

  
rb_red_blk_node* TreeSuccessor(rb_red_blk_node* x) { 
  rb_red_blk_node* y;
  rb_red_blk_node* nil=tree->nil;
  rb_red_blk_node* root=tree->root;

  if (nil != (y = x->right)) {     while(y->left != nil) {       y=y->left;
    }
    return(y);
  } else {
    y=x->parent;
    while(x == y->right) {       x=y;
      y=y->parent;
    }
    if (y == root) return(nil);
    return(y);
  }
}


rb_red_blk_node* TreePredecessor(rb_red_blk_node* x) {
  rb_red_blk_node* y;
  rb_red_blk_node* nil=tree->nil;
  rb_red_blk_node* root=tree->root;

  if (nil != (y = x->left)) {     while(y->right != nil) {       y=y->right;
    }
    return(y);
  } else {
    y=x->parent;
/* XXX: original code was :     while(x == y->left) {  */
    while(x  >  y->left) { 
      if (y == root) return(nil); 
      x=y;
      y=y->parent;
    }
    return(y);
  }
}



void RBTree::RBDelete(int key) {
  rb_red_blk_node* y;
  rb_red_blk_node* x;
  rb_red_blk_node* nil=tree->nil;
  rb_red_blk_node* root=tree->root;
  rb_red_blk_node* z = RBExactQuery(key);

  if (!z) {
    return;
  }

  y= ((z->left == nil) || (z->right == nil)) ? z : TreeSuccessor(z);
  x= (y->left == nil) ? y->right : y->left;
  if (root == (x->parent = y->parent)) {     root->left=x;
  } else {
    if (y == y->parent->left) {
      y->parent->left=x;
    } else {
      y->parent->right=x;
    }
  }
  if (y != z) { 
    
    if (!(y->red)) RBDeleteFixUp(x);
  
    y->left=z->left;
    y->right=z->right;
    y->parent=z->parent;
    y->red=z->red;
    z->left->parent=z->right->parent=y;
    if (z == z->parent->left) {
      z->parent->left=y; 
    } else {
      z->parent->right=y;
    }
    free(z); 
  } else {
    if (!(y->red)) RBDeleteFixUp(x);
    free(y);
  }
  
}

