class Solution {
public:
    double myPow(double x, int n) {
        if(n==0||x==1){
            return 1;
        }
        long num=0;
        if(n<0){
            x=1/x;
            
        }
        num=labs(n);
        double ans=1;long i=0;
       while(num){
           if(num&1)
                ans*=x;
               x*=x;
                num>>=1;
            }
            return ans;
        }

};
