class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int cash=0, hold=-prices[0];
        for(int i=1; i<n; i++)
        {
            cash=max(cash, hold+prices[i]-fee); //selling at this => total cash now= cash left after buying(hold)+prices[i]-fee for completing transaction
            hold=max(hold, cash-prices[i]); //buying at this point using cash
        }
        return cash;
    }
};

/*Intuition and Algorithm

At the end of the i-th day, we maintain cash, the maximum profit we could have if we did not have a share of stock,
and hold, the maximum profit we could have if we owned a share of stock.

To transition from the i-th day to the i+1-th day, we either sell our stock cash = max(cash, hold + prices[i] - fee) 
or buy a stock hold = max(hold, cash - prices[i]). At the end, we want to return cash. We can transform cash first without 
using temporary variables because selling and buying on the same day can't be better than just continuing to hold the stock.*/
