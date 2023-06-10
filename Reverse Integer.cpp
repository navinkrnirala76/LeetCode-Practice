class Solution {
public:
    int reverse(int x) {
    int reversed = 0;

    while (x != 0) {
        // Extract the last digit from x
        int digit = x % 10;

        // Check if reversing x causes overflow or underflow
        if (reversed > std::numeric_limits<int>::max() / 10 || 
            (reversed == std::numeric_limits<int>::max() / 10 && digit > 7)) {
            return 0;
        }
        if (reversed < std::numeric_limits<int>::min() / 10 || 
            (reversed == std::numeric_limits<int>::min() / 10 && digit < -8)) {
            return 0;
        }

        // Append the digit to the reversed number
        reversed = reversed * 10 + digit;

        // Remove the last digit from x
        x /= 10;
    }

    return reversed;
}

        
};
