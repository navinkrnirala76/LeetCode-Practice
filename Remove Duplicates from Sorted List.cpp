class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ans = head;
        while(ans && ans->next){
            if(ans->val == ans->next->val) ans->next = ans->next->next;
            else ans = ans->next;
        }
        return head;
    }
};
