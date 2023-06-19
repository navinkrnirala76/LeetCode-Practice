class Solution {
public:
    bool isTransformable(string s, string t) {
        string s1 = s, t1 = t;
        for(char c='9'; c>='0'; --c) {
            vector<int> ids1, ids2;
            for(int i=0; i<s1.size(); ++i) {
                if(s1[i] == c) ids1.push_back(i);
                if(t1[i] == c) ids2.push_back(i);
            }
            if((int)ids1.size() != (int)ids2.size()) return false;
            for(int i=0; i<ids1.size(); ++i) {
                if(ids1[i] > ids2[i]) return false;
            }
            string s2 = "", t2 = "";
            for(auto &a : s1) {
                if(a < c) s2.push_back(a);
            }
            for(auto &a : t1) {
                if(a < c) t2.push_back(a);
            }
            s1 = s2;
            t1 = t2;
         //   cout<<s1<<" "<<t1<<endl;
        }
        return true;
    }
};
