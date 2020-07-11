class Solution {
public:
    bool winnerSquareGame(int n) {
        int dp[n+1]; dp[0]= 0;
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++) {
            for(int num=1; num*num<=i; num++) {
                if(!dp[i-num*num]) {
                    dp[i]=1; break;
                }
            }
        }
        return dp[n];
    }
};
