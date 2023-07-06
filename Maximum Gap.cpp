class Solution {
public:
    int maximumGap(vector<int>& nums) {
        //if size of the given array is less than 2 there is no use of finding difference
        if(nums.size()<2){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int max=0;
        for(int i=0;i<nums.size()-1;i++){
                if(nums[i+1] -nums[i]>max){
                    max=nums[i+1] -nums[i];
                }
        }
        return max;
    }
};
