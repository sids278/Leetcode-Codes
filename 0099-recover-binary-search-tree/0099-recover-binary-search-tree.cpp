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
    vector<TreeNode*>v;
    
    void inorder(TreeNode*root){
        if(!root)return ;
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
        
    }
    
        
    void recoverTree(TreeNode* root) {
        inorder(root);
        vector<int>ans;
        for(auto x:v){
            ans.push_back(x->val);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            v[i]->val=ans[i];
        }
    }
};