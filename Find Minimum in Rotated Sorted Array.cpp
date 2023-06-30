

class Solution {
public:
    int findMin(vector<int>& nums) {
        int st=0;
        int en=nums.size()-1;
        int minval=INT_MAX;
        while(st<=en){
            if(nums[st]<nums[en]){
                minval=min(minval,nums[st]);
                break;
            }
            int mid=(st+en)/2;
            
            if(nums[st]<=nums[mid]){
                minval=min(minval,nums[st]);
                st=mid+1;
            }
            else{
                minval=min(minval,nums[mid]);
                en=mid-1;
            }
        }
        return minval;
    }
};
