class Solution {
public:
    int shanthi(vector<int>& nums, int tar, vector<int>& dp) {
        if (tar < 0) {
            return 0;
        }
        if (tar == 0) {
            return 1;
        }
        if (dp[tar] != -1) {
            return dp[tar];
        }
        int take = 0;
        for (int i = 0; i < nums.size(); i++) {
            take += shanthi(nums, tar - nums[i], dp);
        }
        return dp[tar] = take;  
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return shanthi(nums, target, dp);
    }
};
