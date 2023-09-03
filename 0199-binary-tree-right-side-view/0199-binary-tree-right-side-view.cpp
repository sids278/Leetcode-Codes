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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(!root)return v;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int s=q.size();
            for(int i=s-1;i>=0;i--){
                TreeNode*f=q.front();
                q.pop();
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
                if(i==0)v.push_back(f->val);
            }
        }
        return v;
    }
};