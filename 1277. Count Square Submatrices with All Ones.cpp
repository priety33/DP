class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        int count=0;
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            dp[i][0]=matrix[i][0];
            count+=dp[i][0];
        }
        for(int j=1;j<n;j++) 
        {
            dp[0][j]=matrix[0][j];
            count+=dp[0][j];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]) dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                else dp[i][j]=0;
                count+=dp[i][j];
            }
        }
        return count;
    }
};

//number of squares with [i][j] as bottom right corner= max square size with [i][j] as bottom right corner.
//all these squares are unique
//total squares= summation of total squares ending at each [i][j]1277. Count Square Submatrices with All Ones
