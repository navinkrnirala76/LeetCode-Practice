class Solution {
public:
    unsigned dp[1001][1001];
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        for(int i = 0; i < m; i++) dp[i][0] = 1;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = (s[i-1] == t[j-1]) ? dp[i-1][j-1] + dp[i-1][j] : dp[i-1][j];
            }
        }  
        return dp[m][n];
    }
};
