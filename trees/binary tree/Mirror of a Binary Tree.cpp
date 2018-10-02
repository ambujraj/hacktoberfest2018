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

// This function returns mirror of the tree
int mirror(struct Node* root)
{
    if (root == NULL)
        return 0;
    
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    cout<<root->key<<" ";
    mirror(root->left);
    mirror(root->right);
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

    mirror(root);
    cout<<endl;
    return 0;
}