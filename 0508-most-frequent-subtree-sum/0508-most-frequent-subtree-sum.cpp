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
    unordered_map<int,int>mp;
    int summer(TreeNode*root){
        if(!root)return 0;
        int sum=root->val+summer(root->left)+summer(root->right);
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int x=summer(root);
        vector<int>v;
        
        int high=INT_MIN;
        for(auto m:mp){
            if(high<m.second)high=m.second;
        }
        for(auto m:mp){
            if(m.second==high)v.push_back(m.first);
        }
        return v;
    }
};