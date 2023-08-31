class Solution {
public:
    int minTaps(int n, vector<int>& r) {
        
        // dp[i] is the min number of tapes to water area from 0 to i
        vector<int> dp(n+1,n+2); // Initialize with max 
        dp[0] = 0;               // minimum tapes needed to water area 0 is 0(basically no area)
        for(int i=0;i<=n;i++)  
        {
            int left = max(0,i-r[i]);     // find the minimum point of garden(area) to water with tape i.
            int right = min(n,i+r[i]);       // find the maximum point of garden(area) to water with tape i.
            for(int j=left+1;j<=right;j++)   
            {                
                //Check if this range from(left..right) can be watered using less number of tapes than previous
                dp[j] = min(dp[j], dp[left]+1); 
            }
        }
        
        // If mimimum tapes needed to water area 0..n is greater than n , it means we could not found minimum number of tapes
        if(dp[n]>=n+2)   
            return -1;
        return dp[n];
    }
};
