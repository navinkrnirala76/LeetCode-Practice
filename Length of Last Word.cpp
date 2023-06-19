class Solution {
public:
    int lengthOfLastWord(string s) {
       stack<char> st;
       int x=0;
        int n = s.length();
       while(s[n] == ' '){
           n--;
       }
       for(int i=s.length()-1; i>=0; i--){
           char ch  = s[i];

           if(s[i]!=' '){

               st.push(ch);
           }
           else if(s[i]==' ' && !st.empty()){
            
              break;
               
           } 
       }
        x = st.size();
        
       return x;
        
    }
};
