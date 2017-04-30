#include "bst.h"

//Binary Tree constructor
BinarySearchTree::BinarySearchTree() {
	root = NULL; //intialize the default construction, set the root to NULL
}

BinarySearchTree::BinarySearchTree(int data) {
	root = NULL;
	this->insert(data);
}

void BinarySearchTree::insert(int data)
{
	Node* p = new Node;
	p->data = data;
	p->left = NULL;
	p->right = NULL;

	if (this->root==NULL) {
		root = p;
	}
	else {
		Node *insertIter = this->root;
		Node *parent = NULL;
		// iterate over the tree until we find the node for insertion
		while (insertIter) {
			parent = insertIter;  // keep track of the parent at the end of iteration
			insertIter = data < insertIter->data
				? insertIter = insertIter->left
				: insertIter = insertIter->right;
		}

		if (data < parent->data) {
			parent->left = p;
		}
		else {
			parent->right = p;
		}

	}
}

void BinarySearchTree::printTree(Node * n, int indent) const
{
	
	if (n != nullptr)
	{
		printTree(n->left, indent + 4);
		if (indent > 0)
			cout << setw(indent) << " ";
		cout << n->data << endl;
		printTree(n->right, indent + 4);
	}

	return;
}

bool checkBST(Node * root)
{
	static struct Node *prev = NULL;
	// traverse the tree in inorder fashion and keep track of prev node
	if (root)
	{
		if (!checkBST(root->left))
			return false;

		// Allows only distinct valued nodes 
		if (prev != NULL && root->data <= prev->data)
			return false;

		prev = root;

		return checkBST(root->right);
	}

	return true;
}



ostream & operator<<(ostream & os, const BinarySearchTree & b)
{
	b.printTree(b.root, 4);
	return cout << "" << endl;
}
