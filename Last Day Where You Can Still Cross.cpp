class Solution {
public:
    using int3 = tuple<int, int, int>;
    using int2 = pair<int, int>;
    struct MyHash
    {
        size_t operator()(const int2& x) const
        {
            hash<int> f;
            size_t digest=(x.first<<3)^f(x.second);
            return digest; 
        }
    };
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int N = cells.size();
        vector<int3> water(N);
        unordered_map<int2, int, MyHash> c2idx;
        vector<int> water1;
        
        // Build water and find indexes for the cell=(i, j) with j=1 storing to water1
        for (int r = 0; r < N; r++) {
            int i = cells[r][0], j = cells[r][1];
            water[r] = {r, i, j};
            c2idx[{i, j}] = r;
        //    cout<<"r="<<r<<" i="<<i<<" j="<<j<<endl;
            if (j == 1) water1.push_back(r);
        }
    //    cout<<water1.size()<<endl;
        
        priority_queue<int3, vector<int3>, greater<int3>> pq;
        unordered_set<int2, MyHash> visited;
        
        for (int idx: water1){
        	int i=cells[idx][0], j=cells[idx][1];
        	int3 w={idx, i, j};
        	pq.push(w);
        	visited.insert({i, j});
		}
        
        int max_d=INT_MIN;
        while (!pq.empty()) {
            auto [d, i, j] = pq.top();
            max_d=max(max_d, d);
        //    cout<<d<<","<<i<<","<<j<<endl;
            if (j==col) {
        //    	cout<<"done ";
        //   	cout<<d<<","<<i<<","<<j<<endl;
                return max_d;
            }
            pq.pop();
            
            vector<int2> adj = {{i + 1, j - 1}, {i + 1, j}, {i + 1, j + 1}, 
            {i, j + 1},{i - 1, j + 1}, {i - 1, j}, {i - 1, j - 1}, {i, j - 1}};
            
            for (const auto& [a, b] : adj) {
                if (a <= 0 || a > row || b <= 0 || b > col || 
				visited.count({a, b})!= 0 ) {
                    continue;
                }
                visited.insert({a, b});
                pq.push({c2idx[{a, b}], a, b});
            }
        }       
        return -1;
    }
};
