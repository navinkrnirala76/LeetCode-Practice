class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int deficit=0;
        int balance=0;
        for(int i=0;i<gas.size();i++)
        {
            balance=balance+gas[i]-cost[i];
            if(balance<0)
            {
                start=i+1;
                deficit+=balance;
                balance=0;
            }

        }
        if(balance+deficit>=0)
        return start;
        return -1;
    }
};
