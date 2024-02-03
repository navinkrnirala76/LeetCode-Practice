#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int n, k;
    vector<int> dp;// dp[i]= max sum for arr[0:i]
    int f(int i, vector<int>& arr){
        if (i<=0) return 0;
        if (dp[i]!=-1) return dp[i];
        int ans=0, maxA=0;
        for (int j=1; j<=k && i-j>=0; j++) {
            maxA=max(maxA, arr[i-j]); // Find max value in the current partition
            ans=max(ans, f(i-j, arr)+j*maxA);
        }
        return dp[i]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->k=k;
        n=arr.size();
        dp.assign(n+1, -1);
        return f(n, arr);       
    }
};
