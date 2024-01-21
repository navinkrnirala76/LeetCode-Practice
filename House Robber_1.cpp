class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        vector<int> s0(2, 0);
        vector<int> s1(2, 0);
        s1[0] = nums[0];

        for (int i = 1; i < n; i++) {
            s0[i % 2] = max(s0[(i - 1) % 2], s1[(i - 1) % 2]);
            s1[i % 2] = s0[(i - 1) % 2] + nums[i];
        }

        return max(s0[(n - 1) % 2], s1[(n - 1) % 2]);
    }
};


