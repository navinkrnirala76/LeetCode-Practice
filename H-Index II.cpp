class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int min = 0, max = n - 1;
        int mid;

        while (min <= max) {
            mid = (min + max) / 2;
            if (citations[mid] < n - mid) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }

        return n - min;
    }
};
