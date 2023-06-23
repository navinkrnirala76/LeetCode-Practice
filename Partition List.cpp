class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head){return NULL;}
        vector<int>v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        vector<int>v1;
        for(int i=0; i<v.size(); i++){
            if(v[i]<x){
                v1.push_back(v[i]);
                v.erase(v.begin()+i);
                i--;
            }
        }
        reverse(v.begin(), v.end());
        for(int i=v1.size()-1; i>=0; i--){
            v.push_back(v1[i]);
        }
        reverse(v.begin(), v.end());
        ListNode* root=NULL;
        for(int i=v.size()-1; i>=0; i--){
            ListNode* temp=new ListNode;
            temp->val=v[i];
            temp->next=root;
            root=temp;
        }
        return root;
    }
};
