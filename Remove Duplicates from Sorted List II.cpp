public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==0||head->next==0)return head;
        int flag=0;
        ListNode*prev=0,*cur=head,*nex=head->next,*dummy=0;
           prev=new ListNode;
            dummy=prev;
        prev->next=head;
        while(nex!=0)
        {
            if(cur->val==nex->val)
            {
                prev->next=nex;
                cur=prev->next;
                nex=cur->next;
                flag=1;
            }
            else if(flag==1)
            {
                 prev->next=nex;
                cur=prev->next;
                nex=cur->next;
                flag=0;
            }
            else
            {
                prev=prev->next;
                cur=cur->next;
              nex=nex->next;      
            }
        }
         if(flag==1)
            {
                prev->next=0;
            }
        return dummy->next;
        
    }
};```
