
class Solution {
public:
    bool solve(string s1,string s2,unordered_map<string,bool> &mp){
        if(s1.length()!=s2.length()){
            return false;
        }
        if(s1.size()==0&&s2.size()==0){
            return true;
        }
        if(s1.compare(s2)==0){
            return true;
        }
        if(s1.length()<=1){
            return false;
        }
        string key = s1+" "+s2;
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        bool ans = false;
        int n = s1.length();
        for(int i = 1; i <= n-1; i++){
            if(solve(s1.substr(0,i),s2.substr(n-i),mp)==true&&solve(s1.substr(i,n-i),s2.substr(0,n-i),mp)==true){
                ans = true;
            }
            if(!ans&&solve(s1.substr(0,i),s2.substr(0,i),mp)==true&&solve(s1.substr(i,n-i),s2.substr(i,n-i),mp)==true){
                ans = true;
            }
        }
        return mp[key] = ans;
    }
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool> mp;
        int n = s1.length();
        return solve(s1,s2,mp);
    }
};
