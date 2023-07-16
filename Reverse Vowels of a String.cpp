class Solution {
public:
    bool isvowel(char ch){
        ch=tolower(ch);
        return ch=='a' || ch=='e' || ch=='o' || ch=='i' || ch=='u';
    }
    string reverseVowels(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;
        while(i<j){
            if(!isvowel(s[i])) i++;
            else if(!isvowel(s[j])) j--;
            else if(i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
             
        }
        return s;
    }
};
