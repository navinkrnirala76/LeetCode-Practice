class Solution {
public:
    
    void solve(int i, vector<vector<int>>& requests,vector<int> &degree,int count,int &ans){
        if(i==requests.size())
        {
            for(auto i:degree){
                if(i!=0) return;
            }
            ans=max(ans,count);
            return ;
        }
        //take
        degree[requests[i][0]]++;
        degree[requests[i][1]]--;
        solve(i+1,requests,degree,count+1,ans);
        degree[requests[i][0]]--;
        degree[requests[i][1]]++;
        //not take
         solve(i+1,requests,degree,count,ans);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> degree(n);
        int ans=0;
        solve(0,requests,degree,0,ans);
        return ans;
        
    }
};
