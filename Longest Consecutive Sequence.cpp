class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        set<int>s;
        vector<int>q;
        if(v.size()==1){
            return 1;
        }
        for(int i=0;i<v.size();i++){
            s.insert(v[i]);
        }
        for(auto &i:s){
            q.push_back(i);
        }
        if(q.size()==1){
            return 1;
        }
        int j=1;
        int ans=0;
        int cnt=1;
        for(int i=0;i<q.size()&&j<q.size();i++){
                if(q[j]-q[i]==1){
                    cnt++;j++;
                }
                else{
                    j=i+2;cnt=1;
                }
                ans=max(ans,cnt);
        }
        return ans;



    }
};
