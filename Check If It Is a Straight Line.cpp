class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        set<int> slopes{};
        int len = coordinates.size();
        sort(coordinates.begin(), coordinates.end());
        
        for(int i{len - 1}; i > 0; i--){
            if(i - 1 >= 0){
                int rise = (coordinates[i][1] - coordinates[i - 1][1]);
                int run = (coordinates[i][0] - coordinates[i - 1][0]);
                int slope{};
                
                if(!run)
                    slope = INT_MIN;
                else slope =  rise / run;
                
                slopes.insert(slope);
                
                if(slopes.size() > 1)
                    return false;
            }
        }
        
        return slopes.size() == 1;
    }
};
