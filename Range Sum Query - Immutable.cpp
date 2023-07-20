class NumArray {
public:
    int pref[10005];
    NumArray(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) pref[i+1] = pref[i] + nums[i];
    }  
    int sumRange(int left, int right) {
        return pref[right + 1] - pref[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
