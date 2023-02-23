class Solution {
public:
    int coord2gridIdx(int i, int j){
        return i/3 * 3 + j/3;
    };
    
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9), cols(9), grids(9);
        pair<set<char>::iterator, bool> ret;
        
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                char c = board[i][j];
                if(c == '.') continue;
                int gridIdx = coord2gridIdx(i, j);
                ret = rows[i].insert(c);
                if(!ret.second) return false;
                ret = cols[j].insert(c);
                if(!ret.second) return false;
                ret = grids[gridIdx].insert(c);
                if(!ret.second) return false;
            }
        }
        
        return true;
        
    }
};
