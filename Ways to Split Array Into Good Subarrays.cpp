int mod = 1e9+7;
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans=1;
        int n=nums.size(),prev=-1;
        for(int i=0;i<n;i++){
            if(nums[i]){
                if(prev!=-1){
                    ans = (ans * (i-prev))%mod;
                }
                prev=i;
            }
        }
        if(prev == -1){
            return 0;
        }
        return ans;
    }
};
