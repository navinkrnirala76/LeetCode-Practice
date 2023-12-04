class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        string largestSubstring = "";

        for (int i = 0; i < num.size(); i++) {
            int j = i + 1;
            int k = j + 1;

            if (k < num.size() && num[i] == num[j] && num[j] == num[k]) {
                ans += num[i];
                ans += num[j];
                ans += num[k];

                largestSubstring = max(ans, largestSubstring);
                ans = "";
            }
        }

        return largestSubstring;
    }
};
