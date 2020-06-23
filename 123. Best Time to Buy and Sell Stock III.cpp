class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if(n==0) return 0;
        //after two iterations profit[i]= Max profit with at most two transactions = 
        //MAX { max profit with one transaction and subarray price[0..i] + max profit with one transaction and aubarray price[i+1..n-1]  }
        vector<int> profit(n);
        profit[n-1]=0;
        int maxprice= prices[n-1];
        for(int i=n-2; i>=0; i--) {
            maxprice= max(maxprice, prices[i]);
            profit[i]= max(profit[i+1], maxprice-prices[i]);
        }
        int minprice= prices[0];
        for(int i=1; i<n; i++) {
            minprice= min(minprice, prices[i]);
            profit[i]= max(profit[i-1], profit[i]+prices[i]-minprice);
        }
        return profit[n-1];
    }
};
