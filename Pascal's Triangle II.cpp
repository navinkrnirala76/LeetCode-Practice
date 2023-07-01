class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> ans;
        ans.push_back(1);
        int n = r, m = 1, temp = 1;
        for(int i=1; i<=r; i++) {
            // cout << temp << " " << n << " " << m << endl;
            temp = (temp *1LL* n) / m;
            n--; m++;
            ans.push_back(temp);
        }
        return ans;
    }
};
