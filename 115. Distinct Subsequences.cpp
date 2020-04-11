class Solution {
public:
    int numDistinct(string s, string t) {
        long long n=s.length();
        if(n==0) return 0;
        long long m=t.length();
        long long dp[m+1][n+1];
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n ;j++)
            {
                if(i==0) dp[i][j]=1; //An empty string is subsequence of all. 
                else if(j==0) dp[i][j]=0; //An empty string can't have another string as suhsequence 
                else if(t[i-1]==s[j-1])
                {
                    dp[i][j]=dp[i][j-1]+dp[i-1][j-1]; // a) All substrings without last character in s
                                                      // b) All substrings without last characters in both
                }
                else dp[i][j]=dp[i][j-1]; // If last characters don't match, then value 
                                          // is same as the value without last character in s.
            }
        }
        return dp[m][n];
    }
};


// Returns count of subsequences of S that match T 
// m is length of T and n is length of S
subsequenceCount(S, T, n, m)

   // An empty string is subsequence of all.
   1) If length of T is 0, return 1.

   // Else no string can be a sequence of empty S.
   2) Else if S is empty, return 0.
    
   3) Else if last characters of S and T don't match,
      remove last character of S and recur for remaining
        return subsequenceCount(S, T, n-1, m)

   4) Else (Last characters match), the result is sum
      of two counts.
        
        // Remove last character of S and recur.
        a) subsequenceCount(S, T, n-1, m) + 

        // Remove last characters of S and T, and recur.
        b) subsequenceCount(S, T, n-1, m-1)   
