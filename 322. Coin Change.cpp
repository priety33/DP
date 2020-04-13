class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(coins.size()==0) return -1;
        long long dp[amount+1]; //long long to compare 1+inf
        for(int i=0;i<=amount;i++) dp[i]=INT_MAX; //memset to INT_MAX does not work
        dp[0]=0;
        for(int i=1; i<=amount; i++)
        {
            for(int j=0;j<coins.size(); j++)
            {
                if(coins[j]<=i) dp[i]=min(dp[i], 1+dp[i-coins[j]]);
            }
        }
        return (dp[amount]<INT_MAX)? dp[amount]:-1;
    }
};
