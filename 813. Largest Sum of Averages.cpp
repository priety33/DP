/* First, we should compute the sum array, which will be helpful when we compute mean value of subarray.
Just like, if we want to compute mean of subarray A[i] ~ A[j], we can use sum[j + 1] - sum[i] / (j + 1 - i).(There we use sum[i] represent the front i's element of A's sum).
Then we simply judge the special case,if K <= 1, we just compute the overall mean, if K >= n, we just return total sum as every single element be a subarray.
Then, we start to construct the dp vector.
dp[i][1] represent the largest sum of averages of front i's element in A when K = 1, namely the mean of subarray A[0] ~A[i - 1].
dp[i][k] = max(dp[i][k], dp[j][k - 1] + 1.0 * (sum[i] - sum[j]) / (i - j)) means we split the k subarray to k -1 subarray in A[0] ~A[j - 1] and one more subarray from A[j] ~A[i - 1], use the sum we already computed, we can get this subarray's mean easily.
Finally, we got the answer dp[n][K], so the total time complexity is O(K*n^2), and the total space complexity is O(n * K). */

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<int> prefixsum(n + 1, 0);
        for(int i = 0; i < n; ++i){
        	prefixsum[i + 1] = prefixsum[i] + A[i];
        }
        if(K <= 1){
        	return (1.0 * sum[n]) / n;
        }
        if(K >= n){
        	return sum[n];
        }
        vector<vector<double>> dp(n + 1, vector<double>(K + 1, 0.0)); //n+1 K+1 taken only to simplify indices 
                                                                      //=> dp[number of elements][number of partions]
        for(int i = 1; i <= n; ++i){
        	dp[i][1] = (1.0 * sum[i]) / i;
        }
        for(int k = 2; k <= K; ++k){
        	for(int i = k; i <= n; ++i){ //start from i=k, because minimum k elements required for a k sized partition
        		for(int j = i - 1; j >= k - 1; --j){ //for kth partition, we are checking max of k-1 partition, => traverse onlt till k-1 elements left                                                      //=> (j>= k-1)
        			dp[i][k] = max(dp[i][k], dp[j][k - 1] + 1.0 * (prefixsum[i] - prefixsum[j]) / (i - j));
                                             //=> dp[number of elements][number of partions]
        		}
        		
        	}
        }
        return dp[n][K];
    }
};
