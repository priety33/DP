class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.length();
        int n=s2.length();
        if(s3.length()!=m+n) return false;
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i+j==0) dp[i][j]=1; //both empty strings => an empty string will be their interleaving
                else if(i==0) dp[i][j]= dp[i][j-1] && s3[j-1]==s2[j-1]; //s1 is empty
                else if(j==0) dp[i][j]= dp[i-1][j] && s3[i-1]==s1[i-1]; //s2 is empty
                else
                {
                    dp[i][j]= (s3[i+j-1]==s1[i-1] && dp[i-1][j]) || (s3[i+j-1]==s2[j-1] && dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

//Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B. 
//C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters 
//in individual strings is preserved. 
