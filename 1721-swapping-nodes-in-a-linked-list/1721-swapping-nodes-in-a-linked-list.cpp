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
    ListNode* swapNodes(ListNode* head, int k) {
        int len=0;
        ListNode*temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }
        temp=head;
        
        int i=k-1;
        while(i--){
            temp=temp->next;
        }
        ListNode*temp2=head;
        int cnt=len-k;
        
        while(cnt && temp2){
            temp2=temp2->next;
            cnt-=1;
        }
        int end=temp2->val;
        temp2->val=temp->val;
        temp->val=end;
        
        return head;
        
        
        

        
        
        
    }
};