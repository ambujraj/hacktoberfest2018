// Given a binary tree, determine if it is height-balanced.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (myBalanced(root) == -1)
            return false;
        return true;
    }
    int myBalanced(TreeNode* root);
};

int Solution :: myBalanced(TreeNode* root) {
    if (root == nullptr)
        return 0;
    
    int l = myBalanced(root->left);
    int r = myBalanced(root->right);
    if (l == -1 || r == -1)
        return -1;
    int diff = abs(l - r);
    if (diff <= 1)
        return max(l, r) + 1;
    else
        return -1;
}
