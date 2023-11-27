class Solution {
    int MOD=1000000007;
    int solve(int n,int i,int count,vector<vector<int>>& map,vector<vector<int>>& dp){
        if(count==n)return 1;
        if(dp[i][count]!=-1)return dp[i][count];

        int sum=0;
        for(auto index:map[i]){
            int temp=solve(n,index,count+1,map,dp)%MOD;
            sum=((sum)%MOD+temp)%MOD;
        }
        return dp[i][count]=sum%MOD;
    }
public:
    int knightDialer(int n) {
        vector<vector<int>>map={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        int ans=0;
        vector<vector<int>>dp(10,vector<int>(n+1,-1));
        for(int i=0;i<10;i++){
            int temp=solve(n,i,1,map,dp);
            ans=((ans)%MOD+temp)%MOD;
        }
        return ans;
    }
};
