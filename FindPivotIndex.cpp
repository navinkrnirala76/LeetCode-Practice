class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int sum1=0,sum2=0;
        for(int i=0;i<nums.size();i++){
            sum1+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            sum1-=nums[i];
            if(sum1==sum2)
            return i;
            sum2+=nums[i];
        }
        
        return -1;
    }
};
