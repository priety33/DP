class Solution {
public:
        int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            int curMax = 0; //at start of each element do curmax=0, and then keep updating curmax for atmost previous k elements
            for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
                curMax = max(curMax, A[i - k + 1]);
                dp[i] = max(dp[i], (i-k>=0 ? dp[i - k] : 0) + curMax * k);
            }
            cout<<dp[i]<<" ";
        }
        return dp[N - 1];
    }
};

/*
Explanation

dp[i] record the maximum sum we can get considering A[0] ~ A[i]
To get dp[i], we will try to change k last numbers separately to the maximum of them,
where k = 1 to k = K.

Complexity

Time O(NK), Space O(N)
*/
