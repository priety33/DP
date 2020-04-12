class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int m=t.size();
        if(m==0) return 0;
        int dp[m][m];
        for(int i=0;i<m;i++)
        {
            for(int j=0; j<=i ;j++)
            {
                if(i+j==0) dp[i][j]=t[i][j];
                else
                {
                    dp[i][j]=t[i][j];
                    if(j==0) dp[i][j]+=dp[i-1][j];
                    else if(j==i) dp[i][j]+=dp[i-1][j-1];
                    else dp[i][j]+= min(dp[i-1][j], dp[i-1][j-1]);
                }
            
            }
        }
        int ans=INT_MAX;
        for(int j=0; j<m; j++)
        {
            ans=min(ans, dp[m-1][j]);
        }
        return ans;
    }
};
