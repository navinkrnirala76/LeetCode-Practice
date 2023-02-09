class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return 0;
        } else if (n==1){
            return 1;
        }
        int first = 1 ;
        int second = 1;
        int ans;
        for(int i =2;i<=n; i++){
            ans = first + second;
            first = second ;
            second = ans;
        }
        return ans;
    }
};
