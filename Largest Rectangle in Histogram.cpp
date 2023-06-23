class Solution {
public:
    vector<int> nextsmaller(vector<int> &v){
    stack<int> st;
    st.push(-1);
    vector<int> ans(v.size());
    for(int i=v.size()-1;i>=0;i--){
        int curr=v[i];
        while(st.top()!=-1&&v[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
    }
    vector<int> prevsmaller(vector<int> &v){
        stack<int> st;
        st.push(-1);
        vector<int> ans(v.size());
        for(int i=0;i<v.size();i++){
            int curr=v[i];
            while(st.top()!=-1&&v[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev=prevsmaller(heights);
        vector<int> next=nextsmaller(heights);
        int size=heights.size();
        int maxlen=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int len=heights[i];
            if(next[i]==-1)
                next[i]=size;
            int width=next[i]-prev[i]-1;
            int area=len*width;
            maxlen=max(maxlen,area);
        }
        return maxlen;
    }
};
