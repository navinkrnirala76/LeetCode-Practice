class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> mp;
        vector<int> in(n);
        queue<int> q;
        for(auto v:prerequisites)
        {
            mp[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            q.push(i);
        }
        cout<<q.size();
        vector<int> ans;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            cout<<t<<"e";
            ans.push_back(t);
            for(int i:mp[t])
            {
                in[i]--;
                if(in[i]==0)
                q.push(i);
            }
        }
        if(ans.size()==n)
        return ans;
        return {};
    }
};
