class Solution {
public:
    bool isPowerOfThree(int n) {
       long ans=0;
       for(int i=0;i<=20;i++) {
           ans=pow(3,i);
           if(ans==n){
               return true;
               break;
           }
    
       }
       return false;
    }
};
