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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode*prev=new ListNode(0);
        prev->next=head;
        unordered_map<int,ListNode*>mp;
        int sum=0;
        mp[0]=prev;
        while(head){
            sum+=head->val;
            mp[sum]=head;
            head=head->next;
        }
        head=prev;
        sum=0;
        while(head){
         sum += head->val;
         ListNode* temp = mp[sum];
         if(temp != head){
            head->next = temp->next;
         }
         head = head->next;
      }
      return prev->next;
    }
};