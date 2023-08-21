class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        string temp = str + str;
        string check = temp.substr(1, temp.size()-2);
        int ans = check.find(str);
        if(ans == -1){
            return false;
        }
        return true;
    }
};
