class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9, curr = 0;
        for(int i : nums) {
            curr += i;
            ans = max(ans, curr);
            if(curr < 0) curr = 0;
        }
        return ans;
    }
};
