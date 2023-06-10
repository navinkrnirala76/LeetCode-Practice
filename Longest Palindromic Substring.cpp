class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0;  // Start index of the longest palindromic substring
        int maxLength = 1;  // Length of the longest palindromic substring

        // Create a boolean table to store the results of substring checks
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // All substrings of length 1 are palindromic
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check substrings of length >= 3
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;  // End index of the substring

                // Check if the substring is palindromic
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;

                    // Update the longest palindromic substring if needed
                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};
