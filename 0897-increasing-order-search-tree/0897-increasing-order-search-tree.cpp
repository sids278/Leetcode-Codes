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
    TreeNode*newH=NULL;
    TreeNode*ans=NULL;
    void maker(TreeNode*root){
        if(!root)return ;
        maker(root->left);
        if(!ans){
            newH=root;
            ans=root;
        }
        else{
            ans->right=root;
            ans=ans->right;
        }
        root->left=NULL;
        maker(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        maker(root);
        return newH;
        
    }
};