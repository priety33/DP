class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        if(n==0) return 0;
        bool dp[n][n];
        for(int i=0; i<n; i++) dp[i][i]=1;
        int count=n;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                dp[i][j]=0;
                if(s[i]==s[j])
                {
                    if(i+1==j) dp[i][j]=1;
                    else if(dp[i+1][j-1]) dp[i][j]=1;
                }
                count+=dp[i][j];
            }
        }
        return count;
    }
};
