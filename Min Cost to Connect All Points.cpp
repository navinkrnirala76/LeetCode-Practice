class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<pair<int, pair<int, int>>> edges;  //create list for each point and distance
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
    int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dis, {i, j}});
            }
        }
        sort(edges.begin(), edges.end()); //Sort edges by distance
        vector<int> parent(n);
        //Each point as its own parent
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        int minCost = 0; //minimum cost
        int numEdges = 0; //number of edges
        // Kruskal's algorithm
        for (auto edge : edges) {
            int dis = edge.first; 
            int u = edge.second.first;
            int v = edge.second.second; 
            int pU = findParent(parent, u); //parent of u
            int pV = findParent(parent, v); //parent of v
            if (pU != pV) {
                parent[pU] = pV; // Union the two sets
                minCost += dis; // Add edge to MST
                numEdges++; // Increase edge count
            }
            // If we have added n-1 edges (spanning tree), break
            if (numEdges == n - 1) {
                break;
            }
        }
        return minCost;
    }
    
private:
    // find the parent of a node
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]);
    }
};
