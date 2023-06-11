class Solution {
public:
    int myAtoi(string s) {


    int i = 0;
    int sign = 1;
    int result = 0;

    // Ignore leading whitespace
    while (i < s.length() && s[i] == ' ') {
        i++;
    }

    // Check sign
    if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Read digits and convert to integer
    while (i < s.length() && isdigit(s[i])) {
        int digit = s[i] - '0';
        
        // Check for overflow
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return (sign == -1) ? INT_MIN : INT_MAX;
        }
        
        result = result * 10 + digit;
        i++;
    }

    return result * sign;
        
    }
};
