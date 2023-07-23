class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       int n=nums.size();
       //max heap
       priority_queue<int>pq;
       for(int x:nums) pq.push(x);
       //put the top large values in odd positions
       //ex-> [1,5,1,1,6,4]------>[_6_5_4_]
       int i=1;
       while(pq.size() and i<n){
           nums[i]=pq.top();
           pq.pop();
           i+=2;
       }
       //put remaining values in even position
       //[1,6,5,1,4,1] 
       int j=0;
       while(pq.size() and j<n){
           nums[j]=pq.top();
           pq.pop();
           j+=2;
       }
     //upvote if u like the solution 
    }
};
