#include <cassert>
#include <cstdio>
#include "BinaryTree.hpp"

BinaryTree::BinaryTree() {
  root = 0;
}

BinaryTree::~BinaryTree() {
  deleteTree(root);
}

void BinaryTree::add(int key) {
  Node* pos = root;
  Node* parent = 0;
  while (pos) {
    parent = pos;
    if (key < pos->key)
      pos = pos->leftChild;
    else if (key > pos->key)
      pos = pos->rightChild;
    else {
      pos->count++;
      return;
    }
  }

  Node* x = new Node;
  x->key = key;
  x->count = 1;
  x->leftChild = x->rightChild = 0;
	
  if (parent && key < parent->key)
    parent->leftChild = x;
  else if (parent && key > parent->key)
    parent->rightChild = x;
  else  // Handle special case of adding to an empty tree.
    root = x;
}

bool BinaryTree::search(int key) {
  Node* x = root;
  while (x) {
    if (key < x->key)
      x = x->leftChild;
    else if (key > x->key)
      x = x->rightChild;
    else
      return true;
  }
  return false;  // No record found.
}

void BinaryTree::drop(int key) {
  Node* x = root;
  Node* xParent = 0;
  while (x) {
    if (key < x->key) {
      xParent = x;
      x = x->leftChild;
    }
    else if (key > x->key) {
      xParent = x;
      x = x->rightChild;
    } else
      break;  // Node found.
  }

  // If the node was not found, there's nothing to remove. 
  if (!x)
    return;

  // Find how many children x has. 
  int numChildren = 0;
  if (x->leftChild)
    ++numChildren;
  if (x->rightChild)
    ++numChildren;

  // Reconfigure the tree based on the number of children of x.
  switch (numChildren) {
  case 0: {
    // If x has no children, just update x's parent.
    if (x == root)
      root = 0;
    else if (x == xParent->rightChild)
      xParent->rightChild = 0; 
    else
      xParent->leftChild = 0;	
    break;
  } case 1: {
      // If x has one child, set x's parent as its parent.
      Node* xChild = ((x->leftChild) ? x->leftChild : x->rightChild);
      if (x == root)
	root = xChild;
      else if (x == xParent->rightChild)
	xParent->rightChild = xChild; 
      else
	xParent->leftChild = xChild;
      break;
    } case 2: {
	// If x has two children, find the smallest descendant y
	// in the right subtree of x.
	Node* y = x->rightChild;
	Node* yParent = x;
	while (y->leftChild) {
	  yParent = y;
	  y = y->leftChild;
	}
			
	// Set y's parent as the parent of y's child and swap
	// the keys in x and y.
	if (yParent == x)
	  yParent->rightChild = y->rightChild;
	else
	  yParent->leftChild = y->rightChild;
	x->key = y->key;
	x = y;
      }
  }
  delete x;
}

unsigned BinaryTree::get_size() {
  return get_size(root);
}

unsigned BinaryTree::get_size(Node* root) {
  if (!root)
    return 0;

  return get_size(root->leftChild) + root->count + get_size(root->rightChild);
}

// Recursively traverse tree, deleting nodes.	
void BinaryTree::deleteTree(Node* root) {
  if (!root)
    return;
  deleteTree(root->leftChild);
  deleteTree(root->rightChild);
  delete root;
}
