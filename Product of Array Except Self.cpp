class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> z, ans(nums.size(), 0); 
      for(int i=0; i<nums.size(); i++) if(nums[i] == 0) z.push_back(i); 
      if(z.size() >1) return ans; 
      else if(z.size() == 0){
      int p = 1; 
      for(int i=0; i<nums.size(); i++) p *= nums[i]; 
      for(int i = 0; i<nums.size(); i++) ans[i] = p/nums[i]; 

      }
      else if(z.size() == 1){
        int p =  1; 
        for(int i=0; i< nums.size(); i++) if(nums[i]!= 0) p *= nums[i]; 
        ans[z[0]] = p; 
        
      }


      return ans; 
    }
       
};
