class Solution {
public:
    vector<int> fun(set<int>& nums1, set<int>& nums2){
        int l1=nums1.size(),l2=nums2.size(),len;
        

        vector<int> ret;

        for(auto it:nums1)
        if(nums2.count(it))
        ret.push_back(it);

        return ret;
        

    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> st,st2;

        for(int i=0;i<nums1.size();i++)
        st.insert(nums1[i]);
        
        for(int i=0;i<nums2.size();i++)
        st2.insert(nums2[i]);

        int f=0,l1=st.size(),l2=st2.size();

        if(l1>l2)
        f++;
        if(f==0){
            return fun(st,st2);
        }
        else{
            return fun(st2,st);
        }
    }
};
