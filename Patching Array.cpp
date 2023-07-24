class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans=0;
       long long int sum=1;
        int m=nums.size();
        for(int i=0;i<m&&sum<=n;)
        {
            if(nums[i]>sum)
            {
                ans++;
                sum=(long long)sum+sum;

            }
            else{
                 sum=(long long)sum+nums[i];
                 i++ ; }
        }
        while(sum<n)
        {
            sum=(long long)sum+sum;
            ans++;
        }
        return ans;
    }
};
