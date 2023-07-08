class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> arr;
        if(s.size() < 10)
            return {};
        for(int i = 0; i < s.size()-9; ++i){
            string str = s.substr(i,10);
            arr[str]++;
        }
        
        vector<string> ans;
        for(auto x: arr){
            if(x.second > 1)
            ans.push_back(x.first);
        }
        
        return ans;
    }
};
