#include<iostream>

struct Node {
    int val;
    Node *left, *right;
    Node(int x) {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};

void flatten(Node *root) {
    if(!root || !root->left&&!root->right)
        return;
    if(root->left) {
        flatten(root->left);
        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right)
            root = root->right;
        root->right = temp;
    }
    flatten(root->right);
}