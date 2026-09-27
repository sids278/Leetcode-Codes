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
    ListNode* partition(ListNode* head, int x) {
        ListNode*newNode= new ListNode(x);
        ListNode* smallNode=new ListNode(-1);
        ListNode* headSmall=smallNode;
        ListNode* headLarger=newNode;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                smallNode->next= new ListNode(temp->val);
                smallNode=smallNode->next;
            }
            else{
                newNode->next= new ListNode(temp->val);
                newNode=newNode->next;
            }
            temp=temp->next;
        }
        if(headSmall->next==NULL)return headLarger->next;
        headSmall=headSmall->next;
        headLarger=headLarger->next;
        smallNode->next=headLarger;
        return headSmall;
    }
};