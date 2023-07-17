class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(__gcd((to_string(nums[i])[0])-'0',nums[j]%10) == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
