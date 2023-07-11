class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> temp1, temp2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        return max(helper(temp1),helper(temp2));


    }

    int helper(vector<int>& temp) {
        int n = temp.size();
        vector<int> dp(n);;

        dp[0] = temp[0];
        int neg = 0;

        for(int i =1;i<n;i++)
        {
            int take = temp[i];
            if(i>1) take += dp[i-2];

            int nottake = 0 + dp[i-1];

            dp[i] = max(take,nottake);
        }

        return dp[n-1];

    }


};
