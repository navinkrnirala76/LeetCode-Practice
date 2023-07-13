class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode*n=node->next;
        node->val=n->val;
        node->next=n->next;
        
    }
};
