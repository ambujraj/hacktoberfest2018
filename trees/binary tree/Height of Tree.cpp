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

// This function returns height of the tree
int height(struct Node* root)
{
    if (root == NULL)
        return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);
    if (lh >= rh)
        return 1+lh;
    else
        return 1+rh;
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

    cout<<height(root)<<endl;
    return 0;
}