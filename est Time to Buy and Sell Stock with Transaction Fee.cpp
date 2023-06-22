class Solution {
public:
    int solve(int i,int &n,vector<int> &v,int &k,vector<vector<int>> &dp,int x){
        if(i>=n)return 0;
        if(dp[i][x]!=-1)return dp[i][x];
        int ans1 = solve(i+1,n,v,k,dp,x);
        int ans2 = 0;
        if(x){
            ans2 = -v[i]-k+solve(i+1,n,v,k,dp,0);
        }else{
            ans2 =  v[i]+solve(i+1,n,v,k,dp,1);
        }
        return dp[i][x] = max(ans1,ans2);
    }
    int maxProfit(vector<int>& v, int fee) {
        int n = v.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,n,v,fee,dp,1);
    }
};
