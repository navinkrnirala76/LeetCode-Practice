class Solution {
public:

    // function to generate maximum number of k digits in the form of vector obtained using elements of array nums.
    vector<int> solve(int k , vector<int> &nums){
        int n = nums.size();
        if(k>n) return {};
        vector<int> ans;
        int rem = n-k;
        ans.push_back(nums[0]);
        // monotonic stack
        for(int i=1 ; i<n ; i++){
            while(!ans.empty() && nums[i]>ans.back() && rem>0){
                ans.pop_back();
                rem--;
            }
            ans.push_back(nums[i]);
        }
        while(rem--){
            ans.pop_back();
        }
        return ans;
    }

    // function to merge two numbers in the form of vectors (v1 and v2) to get the maximum possible number and store it in another vector temp
    void merge(vector<int> &ans , vector<int> &v1 , vector<int> &v2){
        int m = v1.size();
        int n = v2.size();
        int i=0;
        int j=0;
        
        while(i<m && j<n){
            // Case1:
            // ....5 5 5 5 5 7....     .... 5 5 5 5 5 5...
            //     i                        j
            //               tempi                     tempj
            if(v1[i] == v2[j]){
                int tempi= i;
                int tempj= j;
                while(tempi<m && tempj<n && v1[tempi]==v2[tempj]){
                    tempi++;
                    tempj++;
                }
                if(tempj == n){
                    ans.push_back(v1[i]);
                    i++;
                }else if(tempi == m){
                    ans.push_back(v2[j]);
                    j++;
                }else if(v1[tempi]>v2[tempj]){
                    ans.push_back(v1[i]);
                    i++;
                }else{
                    ans.push_back(v2[j]);
                    j++;
                }                
            }
            // Case2 : ....5 6 7 3 4.....     .....2 3 9 8 7....
            //             i                       j
            else if(v1[i] > v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
            // Case2 : ....2 6 7 3 4.....     .....9 3 9 8 7....
            //             i                       j
            else{
                ans.push_back(v2[j]);
                j++;
            }
        }
        // if ......8 9 7   ...3 5 2 8
        //          i                j
        while(i<m){
            ans.push_back(v1[i]);
            i++;
        }
        // if ......8 9 7   ...3 5 2 8
        //              i      j
        while(j<n){
            ans.push_back(v2[j]);
            j++;
        }
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        // We consider every possible case:
        // eg.1 Take maximum number of 0 digits from nums1 and maximum number of k digits from nums2 and merge them to get a maximum number of k digits.
        // eg2. Take maximum number of 1 digits from nums1 and maximum number of k-1 digits from nums2 and merge them to get a maximum number of k digits.
        // eg3. Take maximum number of 2 digits from nums1 and maximum number of k-2 digits from nums2 and merge them to get a maximum number of k digits.
        // eg4. Take maximum number of 3 digits from nums1 and maximum number of k-3 digits from nums2 and merge them to get a maximum number of k digits.
        // and so on.................
        // Then take the maximum among all the above generated numbers as our answer.

        vector<int> ans;
        for(int i=0 ; i<=k ; i++){
            vector<int> temp1 = solve(i , nums1);
            vector<int> temp2 = solve(k-i , nums2);
            vector<int> temp;
            merge(temp , temp1 , temp2);
            if(temp.size() == k) ans = max(ans , temp);
        }
        return ans;
    }
};
