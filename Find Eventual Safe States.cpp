class Solution {
public:
    int n; 
    vector<int> indeg;
    vector<vector<int>> adj;

    void adj_ini(vector<vector<int>>& graph){
        for(int i=0; i<n ; i++){
            for(int j=graph[i].size()-1; j>=0; j--){
                int v=graph[i][j];
                adj[v].push_back(i);
                indeg[i]++;
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n=graph.size();
        indeg.assign(n, 0);
        adj.resize(n);
        adj_ini(graph);
        queue<int> q;

        for(int i=n-1; i>=0; i--)
            if (indeg[i]==0) q.push(i);

        vector<bool> safe(n, 0);
        while(!q.empty()){
            int x=q.front();
        //    cout<<x<<"->";;
            q.pop();
            safe[x]=1;
            for(int y: adj[x]){
        //        cout<<y<<",";
                if (--indeg[y]==0)
                    q.push(y);
            }
        //    cout<<endl;
        }
        vector<int> ans;
        for(int i=0; i<n; i++)
            if (safe[i]) ans.push_back(i);
        return ans;
    }
};
