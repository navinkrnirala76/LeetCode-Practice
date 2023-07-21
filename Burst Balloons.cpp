class Solution {
public:
    int solve(int i, int j, vector<int> &nums)
{
    if (i > j)
    {
        return 0;
    }

    int mx = -1e9;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = nums[i - 1] * nums[ind] * nums[j + 1] + solve(i, ind - 1, nums) + solve(ind + 1, j, nums);
        mx = max(mx, cost);
    }
    return mx;
}

int DP(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mx = -1e9;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = nums[i - 1] * nums[ind] * nums[j + 1] + DP(i, ind - 1, nums, dp) + DP(ind + 1, j, nums, dp);
        mx = max(mx, cost);
    }
    return dp[i][j] = mx;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    // return solve(1, n, nums);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    return DP(1, n, nums, dp);
}
};
