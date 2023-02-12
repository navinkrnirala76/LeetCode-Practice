class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //int n = strs.size();
        if(strs.size()==0){
            return "";
        } 
        string ans = "";
        sort(strs.begin(),strs.end());
        string a = strs[0];
        string b = strs[strs.size()-1];
        
        for(int i =0;i<strs[0].size();i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            } else{
                break;
            }
        }
        return ans;
        
        
    }
};
