#include <bits/stdc++.h>
using namespace std;

// structure For Node
struct Node
{
    struct Node *left, *right;
    int data;
};

// Utility function to create a new Node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Calculation of Height of a Tree
int height(Node *root)
{
    if(!root)
        return 0;
    return max(height(root->left),height(root->right))+1;
}

// Printing Nodes
void NodesAtKthLevel(Node *root,int level,int l)
{

    if(!root)
        return;
    if(level==1)
        {
            cout<<root->data<<" ";
        }
     else if(level>1){
       if(l)
        {
            NodesAtKthLevel(root->left,level-1,l);
            NodesAtKthLevel(root->right,level-1,l);
        }
        else
        {
            NodesAtKthLevel(root->right,level-1,l);
            NodesAtKthLevel(root->left,level-1,l);
        }
     }

}


void printSpiral(Node *root)
{
    int k=height(root);
    bool l=false;
     if(!root)
     return;

     for(int i=1;i<=k;i++)
     {NodesAtKthLevel(root,i,l);
     l=!l;
     }
}
int main()
{
    // Creation of binary tree
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->right->right->left = newNode(7);
    root->left->right->left = newNode(9);

    printSpiral(root);
    return 0;
}

