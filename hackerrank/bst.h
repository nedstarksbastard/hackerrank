#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};


class BinarySearchTree {

public:
	Node* root; //creating the root of the binary tree

	BinarySearchTree();  //check what is an inline function?
	BinarySearchTree(int data); 

	void insert(int item);
	ostream& printTree(ostream & os, Node* n, int indent) const;
	friend ostream& operator<<(ostream& os, const BinarySearchTree& b);
};

// method to check if a given tree is a Binary Search Tree
bool checkBST(Node * root);
