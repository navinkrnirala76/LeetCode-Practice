class Solution {
public:
    int integerBreak(int n) {
    if(n==2||n==3) return n-1;
    int r=n%3;  int q=n/3; int ans=pow(3,q);   
    if(r==0) return ans;
    if(r==1) return pow(3,q-1)*4;
    if(r==2) return ans*2;
    return 0;
    }
};
