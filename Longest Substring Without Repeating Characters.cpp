class Solution {
public:
int lengthOfLongestSubstring(std::string s) {
    int n = s.length();
    int maxLen = 0;
    int left = 0;
    int right = 0;
    std::unordered_set<char> uniqueChars;

    while (right < n) {
        if (uniqueChars.find(s[right]) == uniqueChars.end()) {
            // If the current character is not in the set,
            // add it to the set and expand the window to the right
            uniqueChars.insert(s[right]);
            maxLen = std::max(maxLen, right - left + 1);
            right++;
        } else {
            // If the current character is already in the set,
            // remove the character at the left of the window
            uniqueChars.erase(s[left]);
            left++;
        }
    }

    return maxLen;
}

int main() {
    std::string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;

    return 0;
    }
};
