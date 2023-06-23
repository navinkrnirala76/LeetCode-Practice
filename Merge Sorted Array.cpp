class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
    num1.erase(num1.begin()+m,num1.end());
    for(int i = 0; i<m; i++){
        num1.push_back(num1[i]);
        num1.pop_back();
    }
    for(int i = 0; i<n; i++){
        num1.push_back(num2[i]);
    }
    sort(num1.begin(),num1.end());
    }
};
