class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<float,vector<pair<int,int>>>mp;
       int n=points.size();
       int ans=0;
        for(int i=0;i<n;i++)
        {   int infslope=1;
            for(int j=0;j<n;j++)
            {    if(i==j)
                  continue;
                if(points[j][0]==points[i][0])
                  { infslope++;
                  continue;
                  }
                mp[float(points[j][1]-points[i][1])/(points[j][0]-points[i][0])].push_back({points[j][0],points[j][1]});
            }
            ans=max(ans,infslope);

            for(auto it:mp)
            {  
                int vec_size=(it.second).size();
                ans=max(ans,vec_size+1);
               float a=it.first;
                mp[a].clear();
            }
        }

        return ans;
    }
};
