class Solution {
public:
    double solve(int poured, int row, int glass, vector<vector<double>>& cache)
    {
        if(row < 0 || glass > row || glass < 0)
            return 0;
        
        if(row == 0 && glass == 0)
            return poured;
        
        if(cache[row][glass] != -1)
            return cache[row][glass];
        
        double left = solve(poured, row - 1, glass - 1, cache) - 1;
        if (left < 0) left = 0; // if (row - 1, glass - 1) not full yet
        
        double right = solve(poured, row - 1, glass, cache) - 1;
        if (right < 0) right = 0; // if (row - 1, glass) not full yet
        
        return cache[row][glass] = (left+right)/2;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> cache(100, vector<double>(100, -1));
        return min(1.00, solve(poured, query_row, query_glass, cache));
    }
};
