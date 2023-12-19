class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size() , vector<int> (img[0].size()));

        for (int i=0 ; i<img.size() ; i++){
            for (int j=0 ; j<img[0].size() ; j++){
                int sum = 0 , count = 0;
                for (int dx=-1 ; dx<=1 ; dx++){
                    for (int dy=-1 ; dy<=1 ; dy++){
                        int nr = i + dy;
                        int nc = j + dx;
                        if (nr>=0 && nr<img.size() && nc>=0 && nc<img[0].size()){
                            sum += img[nr][nc];
                            count++;
                        }
                    }
                }
                ans[i][j] = sum/count;
            }
        }    

        return ans;
    }
};
