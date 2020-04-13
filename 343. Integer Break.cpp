
class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        memset(dp,INT_MIN,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                dp[i]=max(dp[i],max(dp[i-j]*j,(i-j)*j));
            }
        }
        //for(int i=0;i<=n;i++) cout << dp[i] <<" ";
        return dp[n];
    }
};
