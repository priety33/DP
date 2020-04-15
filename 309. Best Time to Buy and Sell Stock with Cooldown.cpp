class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0 || n==1) return 0;
        int buy[n], sell[n];
        buy[0]=-prices[0];
        buy[1]=max(buy[0], -prices[1]);
        sell[0]=0;
        sell[1]=max(sell[0], buy[0]+prices[1]);
        
        for(int i=2;i<n;i++)
        {
            sell[i]=max(sell[i-1], buy[i-1]+prices[i]);
            buy[i]=max(buy[i-1], sell[i-2]-prices[i]);
        }
        return sell[n-1];
    }
};
