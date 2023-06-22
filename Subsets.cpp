class Solution {
public:
    //RECURSION - STRIVER
    void f(int index,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans){
        int n=nums.size();
        if(index>=n){
            ans.push_back(ds);
            return;
        }
        f(index+1,nums,ds,ans);
        ds.push_back(nums[index]);
        f(index+1,nums,ds,ans);
        ds.pop_back();
        return;
    } 
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> ds;
        f(0,nums,ds,ans);
        return ans;
     }


    //POWER SET - STRIVER
    // vector<vector<int>> subsets(vector<int>& nums){
    //     vector<vector<int>> TotalSubsets;
    //     int n=nums.size();
    //     for(int num=0;num<=pow(2,n)-1;num++){
    //         vector<int> sub;
    //         for(int i=0;i<=n-1;i++){
    //             if(num&(1<<i)){
    //                 sub.push_back(nums[i]);
    //             }
    //         }
    //         TotalSubsets.push_back(sub);
    //     }
    //     return TotalSubsets;
    // }


    //RECURSION - ADITYA VERMA
    // void solve(vector<int> ip,vector<int> op,vector<vector<int>>& ans){
    //     if(ip.size()==0){
    //         ans.push_back(op);
    //         return;
    //     }
    //     vector<int> op1=op;
    //     vector<int> op2=op;
    //     op2.push_back(ip[0]);
    //     ip.erase(ip.begin()+0);
    //     solve(ip,op1,ans);
    //     solve(ip,op2,ans);
    //     return;
    // }
    // vector<vector<int>> subsets(vector<int>& nums){
    //     vector<vector<int>> ans;
    //     vector<int> op;
    //     solve(nums,op,ans);
    //     return ans;
    // }
};
