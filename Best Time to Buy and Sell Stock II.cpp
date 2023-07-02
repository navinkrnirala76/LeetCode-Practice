class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<int>prev(2, 0);
        vector<int>curr(2, 0);


        for(int idx = n-1; idx>=0; idx--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if(buy)
                {
                    int take = -prices[idx] + prev[0];
                    int notTake = prev[1];

                    profit = max(take, notTake);
                }
                else
                {
                    int take = prices[idx] +  prev[1];
                    int notTake = prev[0];

                    profit = max(take, notTake);
                
                }

                 curr[buy] = profit;
            }
            prev = curr;
        }

        return prev[1];
    }
};
