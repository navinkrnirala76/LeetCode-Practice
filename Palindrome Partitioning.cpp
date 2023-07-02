class Solution {
    
    /*
        Time Complexity : O(2^n*n)
        Space Complexity : O(n)
    */
    
private:
    vector<string> temp;
    vector<vector<string>> res;
    
    void solve(int start, string &s){
        if(start == s.length()){
            res.push_back(temp);
            return;
        }
        
        for(int end=start; end<s.length(); end++){
            if(isPalindrome(start, end, s)){
                // starting index, size
                temp.push_back(s.substr(start, end-start+1));
                solve(end+1, s);
                temp.pop_back();
            }
        }
    }
    
    bool isPalindrome(int start, int end, string s){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        
        return true;
    }
    
public:
    vector<vector<string>> partition(string s) {
        // start, s
        solve(0, s);
        return res;
    }
};
