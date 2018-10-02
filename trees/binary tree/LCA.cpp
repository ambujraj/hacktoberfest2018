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

// This function returns pointer to LCA of two given values n1 and n2.
// This function assumes that n1 and n2 are present in Binary Tree
bool pathToX(struct Node* root, vector <int> &v, int x)
{
    if (root == NULL)
        return false;
    v.push_back(root->key);
    if (root->key == x || pathToX(root->left, v, x) || pathToX(root->right, v, x))
        return true;
    v.pop_back();
    return false;
}

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

    // logic
    // finding out the path from root to these values x and y
    // comparing the path to find LCA
    int x, y;
    cin>>x>>y;
    vector<int> v1;
    vector<int> v2;
    v1.clear();
    v2.clear();
    pathToX(root, v1, x);
    pathToX(root, v2, y);
    int i;
    for (i = 0; i < v1.size() && i < v2.size() && v1[i] == v2[i]; ++i)
    	;
    
    if (i != 0)
        cout<<v1[i-1]<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}