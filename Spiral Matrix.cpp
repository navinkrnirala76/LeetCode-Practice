class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        int st = 0;
        int sz = m * n;
        while (ans.size() < sz) {
            for (int i = st; ans.size() < sz && i < n - st; i++) {
                ans.push_back(mat[st][i]);
            }
            for (int i = st + 1; ans.size() < sz && i < m - st; i++) {
                ans.push_back(mat[i][n - st - 1]);
            }
            for (int i = n - 2 - st; ans.size() < sz && i >= st; i--) {
                ans.push_back(mat[m - 1 - st][i]);
            }
            for (int i = m - 2 - st; ans.size() < sz && i >= st + 1; i--) {
                ans.push_back(mat[i][st]);
            }
            st++;
        }
        return ans;
    }
};
