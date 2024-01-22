class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Sort the array to easily identify the duplicated number
    sort(nums.begin(), nums.end());

    // Initialize an array to store the result
    vector<int> ans(2);

    // Find the duplicated number
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i - 1])
            ans[0] = nums[i];
    }

    // Calculate the sum of the original sequence
    int sum = accumulate(nums.begin(), nums.end(), 0) - ans[0];

    // Calculate the sum of the original sequence from 1 to n
    int orgSum = (nums.size() * (nums.size() + 1)) / 2;

    // Find the missing number
    ans[1] = orgSum - sum;

    return ans;
    }
};
