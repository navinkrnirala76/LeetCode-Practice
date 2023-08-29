class Solution {
public:
    int bestClosingTime(string s) {
        int sum = 0;
        for(auto &i: s){
            sum += (i=='Y');
        }
        int ans = 0, k = 0;
        int x = sum;
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='N')k++;//in prefix string no of NO
            if(s[i]=='Y')sum--;//in suffix no of YES
            if(sum+k<x){//if current penalty < previously calculated penalty than update and
                x = sum+k;
                ans = i+1;
            }
        }
        return ans;
    }
};
