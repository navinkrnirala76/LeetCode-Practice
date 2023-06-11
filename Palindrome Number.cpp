class Solution {
public:
    bool isPalindrome(int x) {
    // Convert the integer to a string
    std::string s = std::to_string(x);

    int i = 0;
    int j = s.length() - 1;

    // Compare characters from the start and end of the string
    while (i < j) {
        if (s[i] != s[j]) {
            return false; // Characters don't match, not a palindrome
        }
        i++;
        j--;
    }

    return true; // All characters match, it's a palindrome

        
    }
};
