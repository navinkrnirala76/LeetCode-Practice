class Solution {
public:
    void solve(int i,int &n,int k,vector<int> &v,vector<int> &tmp,vector<vector<int>> &ans){
        if(k==0){
            ans.push_back(tmp);
            return;
        }
        if(k<0)return;
        if(i>=n)return;
        for(int j = i; j < n; j++){
            tmp.push_back(v[j]);
            solve(j,n,k-v[j],v,tmp,ans);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = v.size();
        solve(0,n,target,v,tmp,ans);
        return ans;
    }
};
