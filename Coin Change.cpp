class Solution {
int solveRec(vector<int>& num,int x)
{
    vector<int>dp(x+1,INT_MAX);
    dp[0]=0;

 for(int i=1;i<=x;i++)
{
    for(int j=0;j<num.size();j++)
    {
     if(i-num[j]>=0&&dp[i-num[j]]!=INT_MAX)
      {
        dp[i]=min(dp[i],1+dp[i-num[j]]);
    }
}
}
if(dp[x]==INT_MAX)
return -1;
return dp[x];
}
public:
    int coinChange(vector<int>& coins, int amount) {
        
        return solveRec(coins,amount);
    }
};
