//same concept as max len sucstring in 2 arrays

//2D dp
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int count=0;
        int n=A.size(), m=B.size();
        if(n==0 || m==0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                count=max(count, dp[i][j]);
            }
        }
        return count;
    }
};

//1D dp
class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        if (!m || !n) return 0;
        vector<int> dp(n + 1);
        int res = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                res = max(res, dp[j] = a[i] == b[j] ? 1 + dp[j + 1] : 0);
            }
        }
        return res;
    }
};
