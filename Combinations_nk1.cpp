class Solution {
void func(int i,int n,int k,vector<vector<int >>&ans,vector<int >&nums,vector<int >&ds){
if(i==n ){

    if(ds.size()==k)ans.push_back(ds);
    return;

}
            ds.push_back(nums[i]);
            func(i+1,n,k,ans,nums,ds);
            ds.pop_back();
      
            func(i+1,n,k,ans,nums,ds);
}
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int >>ans;
        vector<int >ds;
        vector<int >nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        
        func(0,n,k,ans,nums,ds);
        
        return ans;




    }
};
