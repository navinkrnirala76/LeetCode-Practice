class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // initalizing datastructures
        unordered_map<int,vector<int>> groups;
        vector<vector<int>> out;
        
        // iterating through input
        for(int i = 0; i < groupSizes.size(); i++) {
            groups[groupSizes[i]].push_back(i); // add element into map

            // if size == key
            if(groups[groupSizes[i]].size() == groupSizes[i]) {
                out.push_back(groups[groupSizes[i]]); // add to output
                groups[groupSizes[i]] = {}; // reset
            }
        }
        return out;
    }
};
