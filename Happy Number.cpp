class Solution {
public:
    
    int squareDigits(int n){
        int sum=0;
        while(n){
            sum = sum + pow(n%10, 2);
            n = n/10;
        }
        return sum;
    }


    bool isHappy(int n) {
        while(n){
            n = squareDigits(n);
            if(n==1){
                return true;
            }
            else if(n%10 == 5){
                return false;
            }
        }
        return false;        
    }
};
