class Solution {
public:
    
     bool checkPrime(int a){
        int b=sqrt(a);
        int c=2;
        while(c<=b){
        if(a%c==0) return false;
        c++;
        }
        return true;
}
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>res;
        for(int i=2;i<=n/2;i++){
            int temp=n-i;
            if(checkPrime(i) && checkPrime(temp)) res.push_back({i,temp});
        }
        return res;
    }
};
