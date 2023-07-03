class Solution {
public:
    vector<int> adj[2005];
    int dp[2005];
    int help(int i,int n){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=1e9;
        for(auto x:adj[i]){
            int tmp=1+help(x+1,n);
            ans=min(ans,tmp);
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        int check[n][n];      //to store palindromic status of each substring
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    check[i][j]=1;
                }
                else if(g==1){
                    check[i][j]=(s[i]==s[j]);
                }
                else{
                    check[i][j]=(check[i+1][j-1]==1 ? (s[i]==s[j] ? 1 : 0) : 0);
                }
            }
        }
        
        //storing all indexes j in adj[i] such that s[i]...s[j] is palindrome
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check[i][j]){
                    adj[i].push_back(j);
                }
            }
        }

        memset(dp,-1,sizeof(dp));
        return help(0,n)-1;       
    }  
};
