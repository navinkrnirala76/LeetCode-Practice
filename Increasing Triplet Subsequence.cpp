class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MAX, second = INT_MAX, third = INT_MAX;
        for(int i = 0; i < n; i++){
            if(first >=  nums[i]){
               first = nums[i];
            }else if(second >= nums[i] && nums[i] > first ){
                second = nums[i];
            }else if(third >= nums[i] && nums[i] > second){
               third = nums[i];
               return true;
            }
        }

        return false;     
    }
};
