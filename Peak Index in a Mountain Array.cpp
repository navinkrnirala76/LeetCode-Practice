class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(mid==0){
                s++;
                continue;
            }
            if(mid==arr.size()-1){
                e--;
                continue;
            }
            if(arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1])return mid;
            if(arr[mid-1]<arr[mid]){
                s=mid+1;
                continue;
            }
            else{
                e=mid-1;
                continue;
            }
        }
        return -1;
    }
};
