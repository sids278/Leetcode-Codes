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
    ListNode*reverser(ListNode*head,int&k){
        if(!head||head->next==NULL)return head;
        ListNode*temp=head;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        int l=k;
        while(k && temp){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
            k--;
        }
        if(k>0){
            int n=l-k;
            // cout<<prev->val;
            head=reverser(prev,n);
            return head;
            
        }
        head->next=reverser(next,l);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverser(head,k);
    }
};