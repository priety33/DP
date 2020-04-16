class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        if(m==0 || n==0) return 0;
        int dp[m][n];
        int len=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0; j<n;j++)
            {
                if(i==0 && j==0) dp[i][j]= text1[i]==text2[j];
                else if(i==0) 
                {
                    dp[i][j]= text1[i]==text2[j];
                    if(!dp[i][j]) dp[i][j]=dp[i][j-1];
                }
                else if(j==0)
                {
                    dp[i][j]= text1[i]==text2[j];
                    if(!dp[i][j]) dp[i][j]=dp[i-1][j];
                }
                else
                {
                    if(text1[i]==text2[j]) dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
                len=max(len, dp[i][j]);
            }
        }
        return len;
    }
};
