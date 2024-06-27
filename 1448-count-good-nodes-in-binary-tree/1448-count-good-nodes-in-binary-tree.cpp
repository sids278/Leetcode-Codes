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
    int ans=0;
    void dfs(TreeNode*root,int maxC){
        if(!root)return;
        
        if(root->val>=maxC){
            maxC=root->val;
            
            ans++;
        }
        cout<<" root right now "<<root->val<<" max right now "<<maxC<<endl;
        dfs(root->left,maxC);
        dfs(root->right,maxC);
    }
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        int maxC=root->val;
        dfs(root,maxC);
        return ans;
    }
};