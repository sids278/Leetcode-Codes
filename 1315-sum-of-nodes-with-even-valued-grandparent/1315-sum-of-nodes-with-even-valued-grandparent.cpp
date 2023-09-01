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
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        if(root->val%2==0){
            if(root->left && root->left->left)ans+=root->left->left->val;
            if(root->left && root->left->right)ans+=root->left->right->val;
            if(root->right && root->right->left)ans+=root->right->left->val;
            if(root->right && root->right->right)ans+=root->right->right->val;
            
        }
        return ans+sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
    }
};