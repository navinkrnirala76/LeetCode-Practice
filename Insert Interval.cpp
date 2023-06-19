class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        if(intervals.size()==0)
        {
            ans.push_back(newInterval);
            return ans;
        }
        bool flag=false;
        if(newInterval[1]<intervals[0][0])
        {
            ans.push_back(newInterval);
            flag=true;
        }
        ans.push_back(intervals[0]);
        if(intervals.size()==1 && !flag)
        {
            int p=ans.size()-1;
            // Try merging newInterval with ans[p]
            if(newInterval[0]<=ans[p][1])
            {
                int x=min(newInterval[0],ans[p][0]);
                int y=max(newInterval[1],ans[p][1]);
                ans[p]={x,y};
                flag=true;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(!flag)
            {
                int p=ans.size()-1;
                // Try merging newInterval with ans[p]
                if(newInterval[0]<=ans[p][1] && newInterval[1]>=ans[p][0])
                {
                    int x=min(newInterval[0],ans[p][0]);
                    int y=max(newInterval[1],ans[p][1]);
                    ans[p]={x,y};
                    flag=true;
                }
            }
            // Try Merging intervals[i] with ans[p];
            int p=ans.size()-1;
            if(intervals[i][0]<=ans[p][1])
            {
                int x=min(intervals[i][0],ans[p][0]);
                int y=max(intervals[i][1],ans[p][1]);
                ans[p]={x,y};
            }
            else
                ans.push_back(intervals[i]);
        }
        if(!flag)
        {
            int p=ans.size()-1;
            // Try merging newInterval with ans[p]
            if(newInterval[0]<=ans[p][1] && newInterval[1]>=ans[p][0])
            {
                int x=min(newInterval[0],ans[p][0]);
                int y=max(newInterval[1],ans[p][1]);
                ans[p]={x,y};
                flag=true;
            }
            else
                ans.push_back(newInterval);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
