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
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int>mp;
        ListNode*temp=head;
        for(auto x:nums){
            mp[x]=1;
        }
        int co=0;
        while(temp){
            if(mp.find(temp->val)!=mp.end()){
                while(temp && mp.find(temp->val)!=mp.end()){
                    
                    temp=temp->next;
                }
                co++;
            }
            else temp=temp->next;
            
        }
        return co;
        
    }
};