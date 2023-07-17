class Solution {
public:
    int max_element(vector<int>piles){
        int max=piles[0];
        for(int i=1;i<piles.size();i++){
            if(max<piles[i]){
                max=piles[i];
            }
        }
        return max;
    }
    int find(vector<int>piles, int hour){
        int sum=0;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]%hour==0){
                sum+=piles[i]/hour;
            }
            else{
                sum+=(piles[i]/hour)+1;
            }
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = max_element(piles);
        while(start<end){
            int mid = start + (end-start)/2;
            int currsum = find(piles,mid);
            if(currsum<=h){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};
