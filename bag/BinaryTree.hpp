#ifndef _xBINARY_TREE_HPP_
#define _xBINARY_TREE_HPP_

typedef struct Node {
	int key;
  unsigned count;
	Node* leftChild;
	Node* rightChild;	
} Node;

class BinaryTree {

	public:
		BinaryTree();
		~BinaryTree();			
		void add(int);
		bool search(int);
		void drop(int);
    unsigned get_size();

	private:
    unsigned get_size(Node*);
		void deleteTree(Node*);
		Node* root;
};

#endif
