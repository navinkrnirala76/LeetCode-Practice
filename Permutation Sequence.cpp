class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "" ;
        vector<int>ds ;
        for(int i = 1 ; i <= n ; i++){
            ds.push_back(i) ;
        }
        int i = n ;
        while(k!= 0 && i >= 1){
            int r = fact(i-1) ;
            int c = check(r,k) ;
            s += to_string(ds[c]) ;
            ds.erase(ds.begin()+c) ;
            k = k -r*c ;
            i-- ;
        }
        return s ;
    }
    int check(int a ,int k){
        if(k%a == 0)return (k/a) - 1 ;
        return k/a ;
    }
    int fact(int n){
        if(n == 0)return 1 ;
        return n*fact(n-1) ;
    }
};
