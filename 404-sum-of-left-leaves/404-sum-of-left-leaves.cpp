/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // If the node has a left child which is a leaf, 
    //  return its value and continue recursing with the right child.
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) 
            return 0;
        
        if (root->left && !root->left->left && !root->left->right) 
            return root->left->val + sumOfLeftLeaves(root->right);
        
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};