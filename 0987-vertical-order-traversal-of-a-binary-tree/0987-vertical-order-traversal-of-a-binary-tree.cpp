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
    map<int, vector<pair<int, int>>> dict;
    
    void dfs(TreeNode *root, int x, int y) {
        if (!root) return;
        dict[y].emplace_back(x, root->val);
        dfs(root->left, x + 1, y - 1);
        dfs(root->right, x + 1, y + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, 0);
        for (auto &[k, v] : dict) {
            sort(v.begin(), v.end());
            vector<int> col;
            for (auto &p : v) col.emplace_back(p.second);
            ans.emplace_back(move(col));
        }
        return ans;
    }
};