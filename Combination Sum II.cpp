class Solution {
public:
    void solve(int i,int &n,int k,vector<int> &v,vector<int> &tmp,vector<vector<int>> &ans){
        if(k==0){
            ans.push_back(tmp);
            return;
        }if(k<0)return;
        if(i>=n)return;
        for(int j = i; j < n; j++){
            tmp.push_back(v[j]);
            solve(j+1,n,k-v[j],v,tmp,ans);
            while(j+1<n&&v[j]==v[j+1]){
                j++;
            }
            tmp.pop_back();
            
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        vector<int> tmp;
        vector<vector<int>> ans;
        int n = v.size();
        solve(0,n,k,v,tmp,ans);
        return ans;
    }
};
