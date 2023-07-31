class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while (n != 1)
        {
            if ((n & 0b11) != 0b00) return false;
            n >>= 2;
        }
        return true;
    }
};
