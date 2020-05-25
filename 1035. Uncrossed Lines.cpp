class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n= A.size(), m=B.size();
        int dp[n][m];
        for(int j=0; j<m; j++) {
            dp[0][j]= (A[0]==B[j])? 1 : (j>0)? dp[0][j-1] : 0;
        }
        for(int i=1; i<n; i++) {
            dp[i][0]= (A[i]==B[0])? 1 : (i>0)? dp[i-1][0] : 0;
        }
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(A[i]==B[j]) dp[i][j]= 1+dp[i-1][j-1];
                else dp[i][j]= max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[n-1][m-1];
    }
};
