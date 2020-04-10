class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        long long ans=0;
        int m=g.size();
        int n=g[0].size();
        long long dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) dp[i][j]=!g[i][j];
                else if(g[i][j]==1) dp[i][j]=0;
                else if(i==0) dp[i][j]=dp[i][j-1];
                else if(j==0) dp[i][j]=dp[i-1][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>0 && j>0 && g[i][j]==0)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
