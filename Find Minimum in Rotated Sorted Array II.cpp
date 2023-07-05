class Solution {
public:
    int findMin(vector<int>& nums) {
        int m=nums[0];
        for(auto x:nums){
            m=min(m,x);
        }
        return m;
        
    }
};
