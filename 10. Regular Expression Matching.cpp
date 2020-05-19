class Solution {
    public :
    bool isMatch(string s, string p) {
        int n=s.length(), m=p.length();
        int dp[n+1][m+1];
        dp[0][0]=1;
        for(int i=1; i<=n; i++) dp[i][0]=0;
        for(int j=1; j<=m; j++) dp[0][j]= (p[j-1]=='*')? dp[0][j-2] : 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(p[j-1]=='.' || s[i-1]==p[j-1]) dp[i][j]= dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    dp[i][j]=0;
                    //if current char of string matches the char before * in pattern OR char before * is '.'
                    if( s[i-1]==p[j-2] || p[j-2]=='.') dp[i][j] = dp[i-1][j];
                    //taking zero occurence of char before * ie, checking till j-2 char.
                    dp[i][j]= dp[i][j] || dp[i][j-2];
                }
                else if(p[j-1]!=s[i-1]) dp[i][j]=0;
            }
        }
        return dp[n][m];
    }
};
