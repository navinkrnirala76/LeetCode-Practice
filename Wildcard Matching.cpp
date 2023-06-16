class Solution {
    bool solve(string &s, string &p, int i, int j, vector<vector<int>>& dp)
    {
        if(i == 0 && j == 0)
            return true;
        if(j == 0)
            return false;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i == 0) {
            while(j > 0) {
                if(p[j-1] != '*')
                    return dp[i][j] = false;
                j--;
            }
            return dp[i][j] = 1;
        }

        bool res = false;
        if(p[j-1] == '?' || s[i-1]==p[j-1]) {
            res = solve(s, p, i-1, j-1, dp);
        } else if(p[j-1] == '*') {
            res = solve(s, p, i-1, j, dp) | solve(s, p, i, j-1, dp);
        }
        return dp[i][j] = res;
    }

public:
    bool isMatch(string s, string p) 
    {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(s, p, m, n, dp);    
    }
};
