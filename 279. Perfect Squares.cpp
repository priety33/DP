class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        for(int i=0;i<=n;i++) dp[i]=INT_MAX;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int a=sqrt(i);
            while(a)
            {
                dp[i]=min(dp[i], 1+dp[i-(a*a)]);
                a--;
            }
        }
        return dp[n];
    }
};
