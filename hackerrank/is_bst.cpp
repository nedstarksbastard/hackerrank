#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

//Binary Tree class
class BinarySearchTree {
	Node* root; //creating the root of the binary tree

public:
	BinarySearchTree() {
		root = NULL; //intialize the default construction, set the root to NULL
	}

	BinarySearchTree(int data) {
		this->insert(data);
	}

	void insert(int item);
	void printTree(Node* n, int indent) const;
	friend ostream& operator<<(ostream& os, const BinarySearchTree& b);
};

void BinarySearchTree::insert(int data)
{
	Node* p = new Node;
	p->data = data;
	p->left = NULL;
	p->right = NULL;

	if (!root) {
		root = p;
	}
	else {
		Node *insertIter = root;
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

}

bool checkBst(Node * root)
{
	return false;
}

int main() {
	BinarySearchTree *B = new BinarySearchTree();
}

ostream & operator<<(ostream & os, const BinarySearchTree & b)
{
	b.printTree(b.root, 4);
}
