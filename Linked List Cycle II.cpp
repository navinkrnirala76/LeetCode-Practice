/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    bool hasCycle(ListNode *head) {
        ListNode* fast1=head;
        ListNode* slow1=head;
        if(head==NULL || head->next==NULL)
        return false;
        while(fast1!=NULL && fast1->next!=NULL)
        {
            fast1=fast1->next->next;
            slow1=slow1->next;
            if(fast1==slow1)return true;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return NULL;
        if(hasCycle(head)==false)return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        do{
            fast=fast->next->next;
            slow=slow->next;
        }while(fast!=slow);
        fast=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;

    }
};
