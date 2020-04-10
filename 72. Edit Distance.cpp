class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
            }
        }
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i>0 && j>0)
                {
                    if(word2[i-1]==word1[j-1]) dp[i][j]=dp[i-1][j-1];
                    else
                    {
                        dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                    }
                }
            }
        }
        return dp[m][n];
    }
};
