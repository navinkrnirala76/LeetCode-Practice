class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        priority_queue <int> maxh; // Max heap to store the sums of consecutive marble weights in descending order
        priority_queue <int,vector<int>,greater<int>> minh; // Min heap to store the sums of consecutive marble weights in ascending order
        
        // Calculate the sums of consecutive marble weights and add them to both heaps
        for(int i=1;i<n;i++){
            maxh.push(weights[i]+weights[i-1]);
            minh.push(weights[i]+weights[i-1]);
        }
        
        long long maxSum = 0;
        long long minSum = 0;
        k--; // Decrease k by 1 since the first marble is already put
        
        // Remove the k largest and k smallest sums from the heaps and calculate the maximum and minimum sums
        while(k--){
            maxSum += maxh.top();
            maxh.pop();
            minSum += minh.top();
            minh.pop();
        }
        
        // Return the difference between the maximum and minimum sums
        return maxSum - minSum;
    }
};
