// O(n^3)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int dp[n][n];
        for(int i=0;i<n;i++) dp[0][i]=arr[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=INT_MAX;
                for(int k=0;k<n;k++)
                {
                    if(k!=j) dp[i][j]=min(dp[i][j], dp[i-1][k]);
                }
                dp[i][j]+=arr[i][j];
            }
        }
        int sum=INT_MAX;
        for(int i=0;i<n;i++) sum=min(sum, dp[n-1][i]);
        return sum;
    }
};

// O(n^2)
/*
Think about the most straightforward solution: find the minimum element in the first row, 
add it to the minimum element in the second row, and so on.

That should work, unless two minimum elements are in the same column. 
To account for that, let's remember the position pos of the minimum element fm. 
Also, we need to remember the second minimum element sm.

For the next row, we will use fm for columns different than pos, and sm otherwise.
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int dp[n][n];
        int fm= 0, sm=0, pos=-1; //first minimum val in row, second min val in row, position(index) of firstmin
        
        for(int i=0;i<n;i++)
        {
            int curfm=INT_MAX, cursm=INT_MAX, curpos=-1; //minimums in current row
            for(int j=0;j<n;j++)
            {
                dp[i][j]= (j==pos) ? sm : fm;
                dp[i][j]+=arr[i][j];
                
                if(dp[i][j]<=curfm)
                {
                    cursm=curfm;
                    curfm=dp[i][j];
                    curpos=j;
                }
                else if(dp[i][j]>curfm && dp[i][j]<cursm) cursm=dp[i][j];
            }
            sm= cursm, fm= curfm, pos= curpos; //current minimums will act as minimum for next row
        }
        return fm;
    }
};
