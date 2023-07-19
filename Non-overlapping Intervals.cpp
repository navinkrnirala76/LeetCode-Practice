class Solution {
public:
    
    // sort by min. end time
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),compare);
        int n=a.size();
        
        int c=1; // cout of non overlapping intervals
        int e=a[0][1];
        
        for(int i=1;i<n;i++){
            if(a[i][0] >= e){
                c++;
                e=max(e,a[i][1]);
            }
        } 
		
        return n-c;
    }
};
