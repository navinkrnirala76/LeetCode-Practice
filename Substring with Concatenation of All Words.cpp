class Solution {
public:
    unordered_map<string, int> ump;
    bool helper(string s, int idx, int k, int len){
        int count = 0;
        unordered_map<string, int> temp = ump;
        for(int i = idx; i < idx + len * k; i += len){
            string curr = s.substr(i, len);
            if(temp.find(curr) != temp.end()){
                temp[curr]--;
                if(temp[curr] == 0) temp.erase(curr);
                count++;
            }
            else break;
        }
        return count == k;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        int k = words.size();
        for(string word : words){
            ump[word]++;
        }
        vector<int> ans;
        for(int i = 0; i < s.size() - k * len + 1; i++){
            if(helper(s, i, k, len)) ans.push_back(i);
        }
        return ans;
    }
};
