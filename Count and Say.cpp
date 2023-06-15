class Solution {
public:
    string countAndSay(int n) {
        if (n == 1){
            return "1";
        }
        string say = countAndSay(n-1) + "#";
        int cnt = 1;
        char cur = say[0];
        string res = "";
        for(int i = 1; i < say.length(); i++){
            if (cur != say[i]){
                res += (to_string(cnt) + cur);
                cnt = 1;
                cur = say[i];
            }else{
                cnt++;
            }
        }
        return res;
    }
};
