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
    int mod = 1e9 + 7;
    long long ans=INT_MIN;
    unordered_map<TreeNode*,int>sum;
    int f(TreeNode*root){
        if(!root)return 0;
        if(sum.find(root)!=sum.end())return sum[root];
        return sum[root]=root->val+f(root->left)+f(root->right);
    }
    void compute(TreeNode*root,int m){
        if(!root)return;
        long long x=m-sum[root];
        if(x*sum[root]>ans)ans=(x*sum[root]);
        compute(root->left,m);
        compute(root->right,m);
    }
    int maxProduct(TreeNode* root) {
        int m=f(root);
        compute(root,m);
        return ans%mod;
    }
};