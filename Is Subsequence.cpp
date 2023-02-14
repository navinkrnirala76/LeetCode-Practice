class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        while(i<s.length() && j <t.length()){
            if(s[i]==t[j]){
                i=i+1;
                j=j+1;
            } else{
                j=j+1;
            }
             
        }
        return i==s.length();
       
    }
};
