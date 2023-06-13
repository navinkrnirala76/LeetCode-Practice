class Solution {
private:
    bool isValid(string& str){
        queue<char> q;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '('){
                q.push(str[i]);
            }else{
                if(q.empty()) return false;
                q.pop();
            }
        }
        if(q.empty()) return true;
        return false;
    }
    void solve(int n ,vector<string>& ans, string & str){
        if(str.length() >2* n){
            return ;
        }
        if(str.length() == 2*n && isValid(str)){
            ans.push_back(str);
        }
        str+="(";
        solve(n,ans,str);
        str.pop_back();
        str+=")";
        solve(n,ans,str);
        str.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "(";
        solve(n, ans,str);
        return ans;
    }
};
