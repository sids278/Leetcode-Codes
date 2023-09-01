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
    int ans = 0;
    unordered_map<TreeNode*,pair<int,int>> mp;
    int sum(TreeNode* root,int &cnt){
        if(root == NULL){
            return 0;
        }
        cnt++;
        int left = sum(root->left,cnt);
        int right = sum(root->right,cnt);
        return root->val+left+right;
    }
    void helper(TreeNode* root){
        if(!root) return ;
        int cnt = 0;
        int data;
        if(mp.find(root)!=mp.end()){
            data = mp[root].first;
            cnt = mp[root].second;
        }
        else data = sum(root,cnt);
        int avg = data/cnt;
        mp[root].first = data;
        mp[root].second = cnt;
        if(avg == root->val) ans++;
        helper(root->left);
        helper(root->right);
     }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};