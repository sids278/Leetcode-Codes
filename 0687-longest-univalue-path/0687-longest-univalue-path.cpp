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
    int dfs(TreeNode*root){
        if (!root) return 0;

        int leftPath = dfs(root->left);
        int rightPath = dfs(root->right);

        int leftArrow = 0;
        int rightArrow = 0;

        if (root->left && root->left->val == root->val) {
            leftArrow = leftPath + 1;
        }

        if (root->right && root->right->val == root->val) {
            rightArrow = rightPath + 1;
        }

        ans = max(ans, leftArrow + rightArrow);

        return max(leftArrow, rightArrow);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        if(!root->left && !root->right)return 0;
        
        dfs(root);
        return ans;
    }
};