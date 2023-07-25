/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
     TreeNode* solve(int i,int j, vector<int>& help)
    {
        if(i>j) return NULL; // if starting index is greater than ending index simply return NULL;
        int mid=i+(j-i)/2;// calculating mid 
        TreeNode* root=new TreeNode(help[mid]);// making a node with the value of the mid of the vector
// as the vector is sorted , element smaller than the mid will be at the left side of the mid and larger element will be at the right side
        root->left=solve(i,mid-1,help);// for left children
        root->right=solve(mid+1,j,help);// for right children
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
         vector<int>help; // creating a vector help in which all the value of node will be inserted.
         while(head)
         {
            // pushing all the value of the linked list into the vector
             help.push_back(head->val);
             head=head->next;
         }
         int n=help.size(); 
         // here solve(starting index, ending index, vector)
         return solve(0,n-1,help);
    }
};