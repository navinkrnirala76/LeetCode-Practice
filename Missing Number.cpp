class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int k = 1e4+7;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int temp = nums[i]%k;
            if(temp<n)nums[temp] += k;
        }

        int ans = n;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]<k){
                ans=i;
                break;
            }
        }

        return ans;
    }
};
