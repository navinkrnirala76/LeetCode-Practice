class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
		// to store the height of buildings at starting and ending
        vector<pair<int,int>> heights;
        
		// starting height stored as negative and ending is stored as positive
        for(auto it : buildings)
        {
            heights.push_back({it[0],-it[2]});
            heights.push_back({it[1], it[2]});
        }
        
		// sorting the heights according to the occurences
        sort(heights.begin(), heights.end());
        
        vector<vector<int>> ans;
        
		// multiset to store the heights in decreasing order(priority queue)
        multiset<int, greater<int>> ms;
        ms.insert(0);
		
        int preMax = 0;
        
        for(auto it : heights)
        {
			// if height is negative then adding to the set
            if(it.second < 0)
                ms.insert(-it.second);
				
			// if height is positive then removing from the set
            else
                ms.erase(ms.find(it.second));
            
            int curMax = *(ms.begin());
            
			// if current max changes it will add the coordinates to the ans
            if(curMax != preMax)
            {
                ans.push_back({it.first, curMax});
                preMax = curMax;
            }
        }
        
        return ans;
    }
};
