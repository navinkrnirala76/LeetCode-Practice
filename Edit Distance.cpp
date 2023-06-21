class Solution {
public:
    int minDistance(string x, string y) {
        int m = x.size(), n = y.size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=m; i++) dp[i][0] = i;
        for(int j=1; j<=n; j++) dp[0][j] = j;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = (x[i-1] == y[j-1]) ? dp[i-1][j-1] : 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }
        return dp[m][n];
    }
};
