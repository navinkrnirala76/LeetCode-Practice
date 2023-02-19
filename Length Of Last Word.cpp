class Solution {
public:
    int lengthOfLastWord(string s) {
        int length;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==' '){
                i-=1;
            } if(i>=0 && s[i]!=' '){
                length +=1;
            }
        }
        return length;
    }
};
