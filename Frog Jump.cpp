class Solution {
public:
    // Helper function to check if index i is within valid range [0, n]
    bool inline isV(int i, int n) {
        return (i >= 0 && i <= n);
    }
    
    // Recursive function to check if the frog can cross the river
    bool f(map<int, bool>& m, map<pair<int, int>, bool>& dp, int i, int n, int cj) {
        // Base case: If frog jumps beyond the last stone, it can't cross
        if (i > n) return false;
        
        // Base case: If frog reaches the last stone, it can cross
        if (i == n) return true;
        
        // Check if the result for current (i, cj) is already calculated
        if (dp.find({i, cj}) != dp.end()) return dp[{i, cj}];
        
        bool canCross = false;
        
        // Loop through possible jump variations (-1, 0, 1)
        for (int j = -1; j <= 1; j++) {
            if (isV(i + cj + j, n) && cj + j != 0) {
                if (m[i + cj + j]) {
                    // Recursively check if frog can jump from current stone to next stone
                    canCross |= f(m, dp, i + cj + j, n, cj + j);
                }
            }
            if (canCross) break; // If frog can cross, no need to continue
        }
        
        // Store the result in the memoization table and return
        return dp[{i, cj}] = canCross;
    } 
    
    // Main function to check if frog can cross the river using given stones
    bool canCross(vector<int>& s) {
        // Special case: If the second stone isn't reachable by jump size 1, frog can't cross
        if (s[1] != 1) return false;
        
        map<int, bool> m; // Store stone positions for quick access
        map<pair<int, int>, bool> dp; // Memoization table to store computed results
        
        // Mark stones as reachable in the map
        for (int i = 1; i < s.size(); i++) {
            m[s[i]] = true;
        }
        
        // Start recursive check from the second stone with jump size 1
        return f(m, dp, s[1], s.back(), 1);
    }
};
