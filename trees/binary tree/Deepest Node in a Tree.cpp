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

struct DeepNode
{
    struct Node *node;
    int level;
};

struct DeepNode* newDeepNode(Node* node, int level)
{
    DeepNode *temp = new DeepNode;
    temp->level = level;
    temp->node = node;
    return temp;
}

// This function returns deepest_node of the tree
struct DeepNode* deepest_node(struct Node* root)
{
    if (root == NULL)
        return newDeepNode(NULL, 0);
    
    DeepNode* ln = deepest_node(root->left);
    DeepNode* rn = deepest_node(root->right);

    if (!ln->level && !rn->level)
        rn->node = root;
    
    if (ln->level > rn->level) {
        ln->level += 1;
        return ln;
    }
    else {
        rn->level += 1;
        return rn;
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
    root->right->right->left = newNode(7);
    root->left->right->left = newNode(9);

    cout<<deepest_node(root)->node->key<<endl;
    return 0;
}