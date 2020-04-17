class Solution {
public:
    
    bool ispalindrome(string s)
    {
        int i=0, j=s.size()-1;
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        if(n==0) return 0;
        if(ispalindrome(s)) return n; //makes code a lot faster
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1; j<n;j++)
            {
                dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                
                if(s[i]==s[j]) dp[i][j]=max(2+dp[i+1][j-1], dp[i][j]);
            }
        }
        return dp[0][n-1];
    }
};
