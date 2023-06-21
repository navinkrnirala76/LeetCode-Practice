class Solution {
public:
    vector<int> plusOne(vector<int>& v)
     {
        int n = v.size();
        for(int i=n-1; i>=0; i--)
        {
            if(v[i]<9)
            {
                ++v[i];
                return v;
            }
            else
            {
                v[i] = 0;
            }
        }
        v.push_back(0);      
        v[0] = 1;
        return v;
    }
};
