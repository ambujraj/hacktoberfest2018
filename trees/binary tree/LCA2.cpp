#include <iostream>
#include <vector>
using namespace std;

int x, y;
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

// This function returns pointer to LCA
// assuming both are present in the tree
struct Node* LCA(struct Node* root)
{
    if (root == NULL)
        return NULL;
    if (root->key == x)
        return root;
    if (root->key == y)
        return root;
    
    struct Node* ln = LCA(root->left);
    struct Node* rn = LCA(root->right);
    if (ln && rn)
        return root;
    if (ln)
        return ln;
    if (rn)
        return rn;

    return NULL;
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
	root->left->right->left = newNode(9);

    cin>>x>>y;
    cout<<LCA(root)->key<<endl;
    return 0;
}