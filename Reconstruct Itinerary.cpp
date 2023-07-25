class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> neighbors;
        
        for(auto ticket: tickets){
            string node1 = ticket[0];
            string node2 = ticket[1];
            
            neighbors[node1].insert(node2);
        }
        
        stack<string> q;
        q.push("JFK");
        
        vector<string> ans;
        while(!q.empty()){
            string curr = q.top();
            
            if(neighbors[curr].size() == 0){
                ans.push_back(curr);
                q.pop();
            } else {
                auto neighborPointer = neighbors[curr].begin();
                q.push(*neighborPointer);
                neighbors[curr].erase(neighborPointer);
            }
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
