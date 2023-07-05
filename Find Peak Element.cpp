class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) {
                return 0;
            }
            return 1;
        }
        
        int end = nums.size() - 1;
        int start = 0;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }
            else if (mid > 0 && nums[mid - 1] > nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        
        return -1;
    }
};
