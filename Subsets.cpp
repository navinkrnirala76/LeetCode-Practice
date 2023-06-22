class Solution {
public:
    
    void sub(int i,vector<int> &nums, vector<int> &temp,vector<vector<int>>&ans)
    {
        if(i>=nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        // pick
        temp.push_back(nums[i]);
        sub(nums, i+1, temp,ans);

        // not pick
        temp.pop_back();
        //this pop is necessary because we are passing temp by reference. 
        //if anything will be picked in above call it will remain in temp if we will not pop it.
        sub(nums, i+1, temp,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;       
        sub(nums, 0, temp,ans); 
        return ans;
    }
};
