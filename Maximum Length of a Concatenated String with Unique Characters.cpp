#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    bitset<27>no= (1<<27)-1; // Set all 27 bits to 1. for edge case ["aa","bb"]
    bitset<27> charSet(string& s){
        bitset<27> f(0);
        for(char c: s){
            if (f[c-'a'+1]==1) return no;
            f[c-'a'+1]=1;
        }    
        return f;
    }
    bool hasCommon(bitset<27> f1, bitset<27> f2){
        return (f1 & f2).any();
    }

    bitset<27> charUnion(bitset<27>& f1, bitset<27>& f2){
        return f1 | f2;
    }

    int n;
    vector<string> arr;
    vector<bitset<27>> char_a;

    int f(int i, bitset<27> s){
        if (i == n) 
            return s.count(); //return the count of set bits in the bitset
    
        if (char_a[i]==no) return f(i+1, s);
        int has_ai=0;
        // Check if including the current string is possible
        if (!hasCommon(s, char_a[i])){
        //    cout<<i<<": "<<arr[i]<<endl;
            // Include the current string and update the bitset
            bitset<27> newSet = charUnion(s, char_a[i]);
            has_ai=f(i+1, newSet);
        } 
        int no_ai = f(i+1, s);
        return max(has_ai, no_ai);
    }

    int maxLength(vector<string>& arr) {
        n=arr.size();
        this->arr=arr;
        char_a.resize(n);
        for (int i=0; i<n; i++)
            char_a[i]=charSet(arr[i]);

        bitset<27> emptySet(0);
        return f(0, emptySet); 
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
