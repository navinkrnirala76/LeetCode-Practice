class NumArray {
public:
    vector<int> st;
    vector<int> vals;
    int n;
    NumArray(vector<int>& nums): n(nums.size()), st(4*nums.size(),0) {
        vals = nums;
        build(0, 0, n-1);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            st[node] = vals[start];
            return;
        }
        int mid = (start+end)/2;
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        st[node] = st[2*node+1]+st[2*node+2];
    }

    void updateST(int node, int start, int end, int index, int val) {
        if (start == end) {
            st[node] = val;
            return;
        }
        int mid = (start+end)/2;
        if (index<=mid) updateST(2*node+1, start, mid, index, val);
        else updateST(2*node+2, mid+1, end, index, val);
        st[node] = st[2*node+1]+st[2*node+2];
    }

    void update(int index, int val) {
        updateST(0, 0, n-1, index, val);
        vals[index] = val;
    }

    int sumRangeHelper(int node, int start, int end, int left, int right) {
        if (start>right || end<left) return 0;
        if (start>=left && end<=right) return st[node];
        int mid = (start+end)/2;
        int leftSum = sumRangeHelper(2*node+1, start, mid, left, right);
        int rightSum = sumRangeHelper(2*node+2, mid+1, end, left, right);
        return leftSum+rightSum;
    }

    int sumRange(int left, int right) {
        return sumRangeHelper(0, 0, n-1, left, right);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
