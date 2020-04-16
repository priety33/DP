class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if(n<3) return 0;
        int count=0;
        int dp[n]; // dp[i] means the number of arithmetic slices ending with A[i]
        memset(dp, 0, sizeof(dp));
        if(A[2]-A[1]==A[1]-A[0])
        {
            dp[2]=1;
            count++;
        }
        for(int i=3; i<n; i++)
        {
            // if A[i-2], A[i-1], A[i] are arithmetic, then the number of arithmetic slices ending with A[i] (dp[i])
            // equals to:
            //      the number of arithmetic slices ending with A[i-1] (dp[i-1], all these arithmetic slices appending A[i] are also arithmetic)
            //      +
            //      A[i-2], A[i-1], A[i] (a brand new arithmetic slice)
            // it is how dp[i] = dp[i-1] + 1 comes
            
            if(A[i]-A[i-1]==A[i-1]-A[i-2])
            {
                dp[i]=dp[i-1]+1;
                count+=dp[i];
            }
        }
        return count;
    }
};
