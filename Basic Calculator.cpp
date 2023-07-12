class Solution {
public:
    int calculate(string s) {
        int len=s.length();
        stack<int> st;
        
        int sign=1;  //initially take +ve sign
        int currNum=0;
        int ans=0;

        for(int i=0;i<len;i++){
            if(isdigit(s[i])){
                currNum=s[i]-'0';

                while(i+1<len && isdigit(s[i+1])){
                    currNum=(currNum*10)+(s[i+1]-'0');
                    i++;
                }
                currNum=currNum*sign;
                ans+=currNum;
                currNum=0;
            }
            else if(s[i]=='+'){
                sign=1;
            }
            else if(s[i]=='-'){
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(ans);
                st.push(sign);

                sign=1;
                currNum=0;
                ans=0;
            }

            else if(s[i]==')'){
                int prevSign=st.top();
                ans=ans*prevSign;
                st.pop();

                int prevAns=st.top();
                ans+=prevAns;
                st.pop();
            }
        }
        return ans;
    }
};
