class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b){
        if(!a)return b;
        if(!b)return a;
        if(a->val <= b->val){
            a->next = merge(a->next,b);
            return a;
        }else{
            b->next = merge(a,b->next);
            return b;
        }
        return NULL;
    }
    ListNode* mergeKLists(vector<ListNode*>& v) {
        if(v.size()==0)return NULL;
        else if(v.size()==1)return v[0]; 
        for(int i = 1; i < v.size(); i++){
            v[0] = merge(v[0],v[i]);
        }
        return v[0];
    }
};
