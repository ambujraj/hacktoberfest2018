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

// This function returns kthLargest of the tree
int ind = 0;
int k;
void kthLargest(struct Node* root)
{
    if (root == NULL)
        return;
    
    kthLargest(root->right);
    if (++ind == k)
        cout<<root->key<<endl;
    kthLargest(root->left);
}

// Driver program to test above functions
int main()
{
    // Let us create binary search tree given in the above example
    Node * root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->right = newNode(8);
    root->right->right->left = newNode(7);
    root->left->left->left = newNode(1);

    cin>>k;

    kthLargest(root);
    cout<<endl;
    return 0;
}