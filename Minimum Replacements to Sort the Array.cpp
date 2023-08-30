class Solution {
public:
    long long minimumReplacement(std::vector<int>& nums) {
        int n = nums.size();
        long long ops = 0;

        int prev = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > prev) {
                int k = std::ceil(nums[i] / static_cast<double>(prev));
                ops += k - 1;
                prev = nums[i] / k;
            } else {
                prev = nums[i];
            }
        }
        return ops;
    }
};
