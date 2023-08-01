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
    int lh(TreeNode*root){
        if(!root)return 0;
        return 1+lh(root->left);
    }
    int rh(TreeNode*root){
        if(!root)return 0;
        return 1+rh(root->right);
    }
    int countNodes(TreeNode* root) {
        int l=lh(root);
        int r=rh(root);
        
        // If left and right heights are
        // equal return 2^height(1<<height) -1
        if (l == r)
            return (1 << l) - 1;
        // Otherwise, recursive call
        return 1 + countNodes(root->left)
               + countNodes(root->right);
    }
};