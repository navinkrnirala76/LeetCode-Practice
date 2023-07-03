class Solution {
public:
    bool buddyStrings(string s, string p) {
        int n=s.length(), m=p.length();
        if(n!=m) return false;
        
        vector<int> freq(26,0);
        
        int first=-1, second=-1;
        for(int i=0;i<n;i++){
            if(s[i] != p[i]){
                if(first==-1){
                    first=i;
                }else if(second==-1){
                    second=i;
                }else{
                    return false; // more than 2 mismatching characters
                }
            }
            freq[s[i]-'a']++;
        }
        
		// similar strings
        if(first == -1 && second == -1){
            for(int i=0;i<26;i++) if(freq[i] > 1) return true; // can swap similar characters
            return false; // all characters occur only once
        }else if(second == -1){
            return false; // exactly 1 mismatch
        }
        
        return (s[first]==p[second] && s[second]==p[first]); // check similarity on 2 mismatched indexes
    }
};
