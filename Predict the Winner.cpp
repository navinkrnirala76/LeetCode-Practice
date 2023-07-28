class Solution {
public:

    int dp[21][21];
    int solve(int start, int end, vector<int>& nums) {
          if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        if (start == end) {
            return nums[start];
        }
      
        int pickStart = nums[start] - solve(start + 1, end, nums);
        int pickEnd = nums[end] - solve(start, end - 1, nums);

        return dp[start][end]=max(pickStart, pickEnd);
    }

    bool PredictTheWinner(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        memset(dp,-1,sizeof(dp));

        return solve(start, end, nums) >= 0;
    }
};
