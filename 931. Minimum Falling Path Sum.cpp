class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        // dp[i][j] = min path sum ending at this point.
        int dp[n][n];
        for(int i=0;i<n;i++) dp[0][i]=A[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=A[i][j];
                if(j==0) dp[i][j]+= min(dp[i-1][j], dp[i-1][j+1]);
                else if(j==n-1) dp[i][j]+= min(dp[i-1][j-1], dp[i-1][j]);
                else dp[i][j]+= min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1]));
            }
        }
        int sum=INT_MAX;
        for(int i=0;i<n;i++) sum=min(sum, dp[n-1][i]);
        return sum;
    }
};
