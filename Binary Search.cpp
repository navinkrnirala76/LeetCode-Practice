class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0; 
        int j = nums.size()-1;
        for(int i=0;i<=j;){
            int mid = i +(j-i)/2;
            if(nums[mid]==target){
                return mid;
            } else if(nums[mid]>target){
               j = mid -1;
            } else{
                 i = mid +1;
            }
        }
        return -1;
        
        
    }
};
