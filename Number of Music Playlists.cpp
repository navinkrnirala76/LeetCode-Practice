class Solution {
public:
    int dp[101][101];
    int mod=1e9+7;
    int solve(int num,int len,int n,int t,int k)
    {
       if(len==t&&num==n)
       return 1;
       if(len==t)
       return 0;
       if(dp[num][len]!=-1)
       return dp[num][len];
       int newsong=((n-num)*1LL*solve(num+1,len+1,n,t,k))%mod;
       int usedsong=(max(0,num-k)*1LL*solve(num,len+1,n,t,k))%mod;
       return dp[num][len]=(newsong+usedsong)%mod;
    }
    int numMusicPlaylists(int n, int t, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,t,k);
    }
};
