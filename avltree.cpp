#include <climits>
#include <cmath>
#include <cstdio>
#include <cassert>

/* Example code taken from http://kukuruku.co/hub/cpp/avl-trees */

struct node {
    int key;
    unsigned char height;
    node* left;
    node* right;
    node(int k) { key = k; left = right = 0; height = 1; }
};

/* Helpers */

unsigned char height(node* p) {
    return p?p->height:0;
}

int bfactor(node* p) {
    return height(p->right)-height(p->left);
}

void fixheight(node* p) {
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

node* rotateright(node* p) {
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

node* rotateleft(node* q) {
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

node* balance(node* p) { // balancing the p node
    fixheight(p);
    if( bfactor(p)==2 ) {
        if( bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // balancing is not required
}

/* Operations on Tree */

node* insert(node* root, int k) { // insert k key in a tree with root root
    if( !root ) return new node(k);
    if( k<root->key )
        root->left = insert(root->left,k);
    else
        root->right = insert(root->right,k);
    return balance(root);
}

node* findmin(node* p) { // find a node with minimal key in a p tree 
    return p->left?findmin(p->left):p;
}

node* removemin(node* p) { // deleting a node with minimal key from a p tree
    if( p->left==0 )
        return p->right;
    p->left = removemin(p->left);
    return balance(p);
}

node* remove(node* p, int k) { // deleting k key from p tree
    if( !p ) return 0;
    if( k < p->key )
        p->left = remove(p->left,k);
    else if( k > p->key )
        p->right = remove(p->right,k);  
    else { //  k == p->key 
        node* q = p->left;
        node* r = p->right;
        delete p;
        if( !r ) return q;
        node* min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

/* Checker Functions */

int max(int a, int b) {
  return (a >= b)? a: b;
}    

int get_height(struct node* node) {
   if(node == NULL)
       return 0;
   return 1 + max(height(node->left), height(node->right));
} 

// Returns true if binary tree with root as root is height-balanced 
bool isBalanced(node *root) {
   int lh; /* for height of left subtree */
   int rh; /* for height of right subtree */ 
 
   if(root == NULL)
    return 1; 
 
   lh = get_height(root->left);
   rh = get_height(root->right);
 
   if( std::abs(lh-rh) <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right))
     return 1;
 
   return 0;
}
 
// Helper function: Returns true if the given tree is a BST and its values are >= min and <= max. 
int isBSTUtil(node* node, int min, int max) {
  if (node == NULL) 
     return 1;
  if (node->key < min || node->key > max) 
     return 0; 
 
  return
    isBSTUtil(node->left, min, node->key) && 
    isBSTUtil(node->right, node->key, max);
} 

// Checks correctness of binary search tree structure
int isBST(node* node) {
  return(isBSTUtil(node, INT_MIN, INT_MAX)); 
} 

int main() {
  node* root = new node(0);
  insert(root, 1);
  assert(isBalanced(root));
  assert(isBST(root));
}
