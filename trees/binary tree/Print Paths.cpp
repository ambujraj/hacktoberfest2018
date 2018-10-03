// Given a binary tree, print all of the paths from the root to leaf nodes
#include <iostream>
#include <vector>
using namespace std;

// A Binary Tree Node
struct Node
{
	struct Node *left, *right;
	int key;
};

// Utility function to create a new tree Node
Node* newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

// This function print_paths of the tree
void print_paths(struct Node* root, vector<int> &v)
{
	if (root == NULL)
		return;

	v.push_back(root->key);
	print_paths(root->left, v);
	print_paths(root->right, v);

	if (!root->left && !root->right) {
		for (int i = 0; i < v.size(); ++i)
			cout<<v[i];
		cout<<endl;
	}
	v.pop_back();
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the above example
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);
	root->right->right->left = newNode(7);
	root->left->left->right = newNode(9);

	vector<int> v;
	print_paths(root, v);
	cout<<endl;
	return 0;
}