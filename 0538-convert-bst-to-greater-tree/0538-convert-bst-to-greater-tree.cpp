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
    
    void convertBST(TreeNode* root, int& s) {
    if (!root) return;

        convertBST(root->right, s); // Traverse right subtree first

        root->val += s; // Update the node value with the sum of greater nodes
        s = root->val; // Update the sum of greater nodes with the new value

        convertBST(root->left, s); // Traverse left subtree
    }

    TreeNode* convertBST(TreeNode* root) {
        int s = 0;
        convertBST(root, s);
        return root;
    }

};