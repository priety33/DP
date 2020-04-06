//buy at every local minima, sell at local maxima.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0;
        int lmin=INT_MAX;
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i]<=lmin)
            {
                lmin=prices[i];
            }
            else
            {
                mp+=prices[i]-lmin;
                lmin=prices[i];
            }
        }
        return mp;
    }
};
