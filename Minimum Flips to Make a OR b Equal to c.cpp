class Solution {
public:
    string binary(int num){
        int temp = 1;
        while(temp<=num){
            temp*=2;
        }
        temp/=2;
        string ans = "";
        while(temp>=1){
            if(temp<=num){
                num -= temp;
                ans += "1";
            }
            else{
                ans += "0";
            }
            temp/=2;
        }
        return ans;
    }

    int minFlips(int a, int b, int c) {
        string x = binary(a);
        string y = binary(b);
        string z = binary(c);
        //cout << x << " " << y << " " << z;

        int ans=0;
        int u=x.length()-1,v=y.length()-1,w=z.length()-1;
        while(u>=0 && v>=0){
            if(w<0){
                if(x[u]=='1') ans++;
                if(y[v]=='1') ans++;
                u--; v--; continue;
            }
            else if(z[w]=='1'){
                if(x[u]=='0' && y[v]=='0') ans++;
            }
            else if(z[w]=='0'){
                if(x[u]=='1') ans++;
                if(y[v]=='1') ans++;
            }
            u--;
            v--;
            w--;
        }
        while(u>=0){
            if(w<0){
                if(x[u]=='1') ans++;
                u--; continue;
            }
            else if(z[w]=='1' && x[u]=='0') ans++;
            else if(z[w]=='0' && x[u]=='1') ans++;
            u--;
            w--;
        }
        while(v>=0){
            if(w<0){
                if(y[v]=='1') ans++;
                v--; continue;
            }
            else if(z[w]=='1' && y[v]=='0') ans++;
            else if(z[w]=='0' && y[v]=='1') ans++;
            v--;
            w--;
        }
        while(w>=0){
            if(z[w]=='1') ans++;
            w--;
        }
        return ans;
    }
};
