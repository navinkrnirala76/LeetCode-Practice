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
    ListNode* oddEvenList(ListNode* head) {
        vector<int>v;
        ListNode* rt=head;
        ListNode* rt1=head;
        int j=0;
        while(rt){
            if(!(j&1)){v.push_back(rt->val);}
            rt=rt->next;
            j++;
        }
        int j1=0;
        while(rt1){
            if(j1&1){v.push_back(rt1->val);}
            rt1=rt1->next;
            j1++;
        }
        //for(int i=0; i<v.size(); i++){cout<<v[i]<<" ";}cout<<endl;
        ListNode* root=NULL;
        int i=0;
        while(i<v.size()){
            ListNode* ans=new ListNode;
            ans->val=v[i];
            i++;
            ans->next=root;
            root=ans;
        }
        ListNode* current=root;
        ListNode *prev = NULL, *next = NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        root=prev;
        return root;
    }
};
