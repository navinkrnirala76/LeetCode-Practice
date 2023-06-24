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
    ListNode* reverse(ListNode* head,ListNode* l2){
        if(head== NULL || head->next == NULL)return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != l2){
            next = curr->next;
            curr->next=prev;

            prev = curr;
            curr= next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL)return head;

        ListNode* temp = head;
        ListNode* prev = NULL;

        int cnt =1;

        while(temp->next && cnt != left){
            prev = temp;
            temp = temp->next;
            cnt++;
        }

    ListNode* temp2 = temp;
        while(temp2->next && cnt!= right){
            temp2 = temp2->next;
            cnt++;
        }
        ListNode* check = temp2->next;

        ListNode* newhead= reverse(temp,check);
       
       if(prev!=NULL){
       prev->next =  newhead;
        temp->next = check;
        return head;
       }
        temp->next = check;
        return newhead;
    }
};
