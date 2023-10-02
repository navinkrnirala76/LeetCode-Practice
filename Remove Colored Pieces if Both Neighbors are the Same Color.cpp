class Solution {
public:
    bool winnerOfGame(string colors) {
        int player[2]={0};
        int n=colors.size();
        int len=1;
        char prev=colors[0];
        #pragma unroll
        for(int i=1; i<n; i++){
            char c=colors[i];
            if (prev==c) len++;
            else len=1;
            if (len>2) player[c-'A']++;
            prev=c;
        }
        return player[0]>player[1];
    }
};
