class Solution {
public:
int solve(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0 ; 
    }

    if (dp [n] != -1)
    {
        return dp[n] ; 
    }
    // ans initially equal to n -> the maximum number of perfect sqaure
	// by forming 1 by adding 1 sqaure repeatively
    // Finding minimum therefore, initialize with highest possible value 
    int ans = n ; 
    for (int i = 1 ; i * i <= n ; i ++)
    {
        int temp = i * i ;
        ans = min(ans, solve(n - temp, dp) + 1) ;
    }
    dp[n] = ans ; 
    return dp[n] ;  
}
    int numSquares(int n) {
        vector<int> dp (n + 1, -1) ; 
        return solve(n, dp) ; 
    }
};
