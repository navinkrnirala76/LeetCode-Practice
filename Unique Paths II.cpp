class Solution {
public:
    int nl, ml, a[105][105], dp[105][105];

    bool valid(int x, int y) {
        if(x < nl and y < ml and a[x][y] == 0) return true;
        else return false;
    }

    int solve(int i, int j) {
        if(!valid(i, j)) return 0;
        if(i >= nl-1 and j >= ml-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = solve(i+1, j) + solve(i, j+1);
        return dp[i][j] = ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        nl = obstacleGrid.size(), ml = obstacleGrid[0].size();
        for(int i=0; i<nl; i++) for(int j=0; j<ml; j++) a[i][j] = obstacleGrid[i][j];
        int ans = solve(0, 0);
        return ans;
    }
};
