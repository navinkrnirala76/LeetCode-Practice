class Solution {
public:
    
    int check(vector<int> adj[], int itr,vector<int>& informTime)
    {
        int ans=0;
// Iterating through the tree nodes and checking for the path with maximum length.
        for(int i=0;i<adj[itr].size();i++)
        {
            ans=max(ans,check(adj,adj[itr][i],informTime));
        }
        ans+=informTime[itr];

        return ans;
    }
    
    
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
// Creating the structure of Tree.
        vector<int> adj[n];
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }

        int ans=check(adj,headID,informTime);
        return ans;
    }
};
