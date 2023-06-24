class Solution {
public:
    int numDecodings(string s) {
        std::vector<int> curr(2, 0);
        std::vector<int> prev(2, 0);

        int n = s.size();

        prev[false] = 1;
        prev[true] = s.back() != '0';

        for(int i = n-1; i >= 0; --i) {
            for(int isPrevSelected = 0; isPrevSelected <= 1; ++isPrevSelected) {
                if(isPrevSelected == 0) {
                    curr[isPrevSelected] = prev[true];
                    continue;
                }

                if(i > 0 && s[i-1] == '0') {
                    curr[isPrevSelected] = 0;
                    continue;
                }
                
                int takeCurrent = prev[true];
                int takeNext = 0;
                if(i > 0 && (std::string(1,s[i-1]) + s[i]) <= "26") {
                    takeNext = prev[false];
                }
                curr[isPrevSelected] = takeCurrent + takeNext;
            }
            prev = curr;
        }

        return prev[0];
    }
};
