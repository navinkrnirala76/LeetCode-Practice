class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==-1)  continue;
            for(int j=i+1;j<n;j++)
            {
                if(abs(nums[j]-nums[i])<=target)   dp[j]=max(dp[i]+1,dp[j]);
            }
        }
        return dp[n-1];
    }
};
