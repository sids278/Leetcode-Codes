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
    
        long long prev=LLONG_MIN;
        bool isValidBST(TreeNode* root) {
            if(root==NULL)return true;
            if(isValidBST(root->left)==false)return false;
            if(root->val<=prev)return false;
            prev=root->val;
            return isValidBST(root->right);
        }


        void make_tree(TreeNode* &root,unordered_map<int,TreeNode*>&m )
        {
            if(!root)return;
            if(root->left)
            {
                if(m[root->left->val]){
                root->left=m[root->left->val];
                m[root->left->val]=NULL;
                }
            }
            if(root->right)
            {
                if(m[root->right->val]){
                root->right=m[root->right->val];
                    m[root->right->val]=NULL;
                }
            }
            make_tree(root->left,m);
            make_tree(root->right,m);
        }




        TreeNode* canMerge(vector<TreeNode*>& trees) {
            unordered_map<int,int>nodes;  //map to store freq of root nodes
            for(auto x:trees)
            {
                nodes[x->val]++;
                if(x->left)nodes[x->left->val]++;
                if(x->right)nodes[x->right->val]++;
            }
            TreeNode* curr=NULL;      //root node of combined tree
            for(auto x:trees)
            {
                if(nodes[x->val]==1)    //if a root node val is not equals to leaf of any other root, then it can be for root node of comibed tree
                {
                    if(curr!=NULL)return NULL; //not more than 1 root can exist for combined tree
                    curr=x;
                }
            }
            unordered_map<int,TreeNode*>m; //map to store root nodes
            for(auto x:trees)
            {
                m[x->val]=x;
            }
            make_tree(curr,m); //function to combine all BSTs
            int count=0;
            for(auto x:m)
            {

                if(x.second!=NULL)count++;   //to check if all BSTs have been included
            }
            if(count>1)return NULL;
            if(isValidBST(curr))return curr;   //check if tree formed is a valid BST or not
            return NULL;



        }
        
    
};