class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map1; // Create an unordered map to store anagrams
        
        // Iterate over each string in the input vector
        for (auto x : strs) {
            string temp = x;
            sort(temp.begin(), temp.end()); // Sort the characters of the current string
            
            map1[temp].push_back(x); // Add the sorted string as a key in the map and push the original string to the corresponding value vector
        }
        
        vector<vector<string>> final_ans;
        
        // Iterate over the map
        for (auto it : map1) {
            final_ans.push_back(it.second); // Push the value vector (group of anagrams) into the final answer vector
        }
        
        return final_ans; // Return the final answer vector
    }
};
