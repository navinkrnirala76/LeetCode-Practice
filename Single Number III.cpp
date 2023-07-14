class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long Xor_val = 0;
        for(int i = 0 ; i<nums.size();i++)
            Xor_val^=nums[i];
        long long diffBit =  Xor_val & (-Xor_val);
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i<nums.size();i++){
            if(diffBit & nums[i])
                ans1^=nums[i];
            else
                ans2^=nums[i];
        }
        return {ans1,ans2};
    }
};
