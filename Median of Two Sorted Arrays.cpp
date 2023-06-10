class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int totalSize = m + n;

        if (totalSize % 2 == 1) {
            return findKthElement(nums1, nums2, totalSize / 2 + 1);
        } else {
            int left = findKthElement(nums1, nums2, totalSize / 2);
            int right = findKthElement(nums1, nums2, totalSize / 2 + 1);
            return (left + right) / 2.0;
        }
    }

private:
    int findKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0;
        int j = 0;

        while (true) {
            // Handle cases where one array is exhausted
            if (i == m) {
                return nums2[j + k - 1];
            }
            if (j == n) {
                return nums1[i + k - 1];
            }

            // Handle the base case of k = 1
            if (k == 1) {
                return min(nums1[i], nums2[j]);
            }

            // Find the indices to compare
            int half = k / 2;
            int newIndex1 = min(i + half, m) - 1;
            int newIndex2 = min(j + half, n) - 1;
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];

            // Recursively reduce the problem size
            if (pivot1 <= pivot2) {
                k -= newIndex1 - i + 1;
                i = newIndex1 + 1;
            } else {
                k -= newIndex2 - j + 1;
                j = newIndex2 + 1;
            }
        }
    }
};
