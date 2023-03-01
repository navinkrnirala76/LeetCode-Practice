class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> r;
        for(int i=0;i<nums.size();i++){
            if(r.find(nums[i])!=r.end()){
                return true;
            }
            r.insert(nums[i]);
        }
        return false;
    }
        
};
