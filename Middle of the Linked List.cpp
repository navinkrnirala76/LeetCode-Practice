class Solution {
    queue<ListNode*> q;
public:
    ListNode* middleNode(ListNode* head) {
        if( head != NULL )
        {
            while( head != NULL )
            {
                q.push(head);
                head = head->next;
            }
            int n = q.size()/2;
            while(n--)
                q.pop();
            return q.front();
        }
        return NULL;
    }
};
