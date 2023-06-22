class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        map<int, int> mp;
        for(auto it : nums) {
            mp[it]++;
            if(mp[it] <= 2) nums[k++] = it;
        }
        return k;
    }
};
