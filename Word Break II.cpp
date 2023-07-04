class Solution {
public:
void solve(int i,int &n,string s1,string s2,string &s,unordered_set<string> &st,vector<string> &ans){
    if(i>=n){
        cout<<s2<<" "<<s1<<endl;
        if(st.count(s1)){
            s2 += s1;
            ans.push_back(s2);
        }
        return;
    }
    string str = "";
    if(st.count(s1)){
        solve(i+1,n,str+s[i],s2+s1+" ",s,st,ans);
    }
    solve(i+1,n,str+s1+s[i],s2,s,st,ans);
}
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        unordered_set<string> s;
        for(auto &i: wordDict){
            s.insert(i);
        }
        vector<string> ans;
        int n = str.length();
        solve(0,n,"","",str,s,ans);
        // for(auto &i: ans)i.pop_back();
        return ans;
    }
};
