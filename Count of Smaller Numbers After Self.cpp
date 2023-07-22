class Solution {
    void merge(int l,int mid,int h,vector<int> &nums,vector<int> &cnt,vector<int> &index)
    {
        int n = mid-l+1;
        int m = h-mid;

        vector<int> left(n);
        vector<int> right(m);
        // cout << "left : ";
        for(int i=0;i<n;i++)
        {
            left[i] = index[i+l];
            // cout << left[i] << " ";
        }
        // cout << endl;
        // cout << "right : ";
        for(int i=0;i<m;i++)
        {
            right[i] = index[i+mid+1];
            // cout << right[i] << " ";
        }
        // cout << endl;
        int i=0,j=0;
        int k = l;
        while(i<n && j<m)
        {
            if(nums[left[i]] > nums[right[j]])
            {
                cnt[left[i]] += (m-j);
                index[k++] = left[i++];
            }
            else
            {
                index[k++] = right[j++];
            }
        }
        while(i<n)
        {
            index[k++] = left[i++];
        }
        while(j<m)
        {
            index[k++] = right[j++];
        }
    }
    void mergeSort(int l,int h,vector<int> &nums,vector<int> &cnt,vector<int> &index)
    {
        if(l>=h)
            return;
        int mid = l + (h-l)/2;
        mergeSort(l,mid,nums,cnt,index);
        mergeSort(mid+1,h,nums,cnt,index);

        merge(l,mid,h,nums,cnt,index);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> index(n);
        vector<int> cnt(n);
        for(int i=0;i<n;i++)
        {
            index[i] = i;
        }
        mergeSort(0,n-1,nums,cnt,index);

        return cnt;
    }
};
