class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            
            ans = (ans ^ nums[i]) & ~cnt;
            cnt = (cnt ^ nums[i]) & ~ans;
        }
        return ans;

    }
};
