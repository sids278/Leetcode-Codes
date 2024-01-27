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
    vector<int>inorder;
    unordered_map<int,int>mp;
    void order(TreeNode* root){
        if(!root)return ;
        order(root->left);
        inorder.push_back(root->val);
        mp[root->val]=1;
        order(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        order(root);
        vector<vector<int>> ans;

        for (auto x : queries) {
            if(mp.find(x)!=mp.end())ans.push_back({x,x});
            else{
                auto upper = upper_bound(inorder.begin(), inorder.end(), x);
                auto lower = lower_bound(inorder.begin(), inorder.end(), x);

                int up = (upper != inorder.end()) ? *upper : -1;
                int low = (lower != inorder.begin()) ? *(--lower) :-1;

                ans.push_back({low, up});
            }
        }

        return ans;
    }
};