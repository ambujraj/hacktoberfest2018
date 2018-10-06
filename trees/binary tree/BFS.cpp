#include <iostream>
#include <queue>
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

// This function prints BFS of the tree
void BFS(struct Node* root)
{
    queue <Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        cout<<temp->key<<" ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
        q.pop();
    }
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->right->left = newNode(7);
    root->right->right->left = newNode(9);

    BFS(root);
    cout<<endl;
    return 0;
}