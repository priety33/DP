class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        dp[0]=1;
        for(int sum=1; sum<=target; sum++) {
            for(auto coin: nums) {
                if(sum>=coin) dp[sum]+= dp[sum-coin];
            }
        }
        return dp[target];
    }
};

/*class Solution { // Coin Change 2
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = 1; i <= amount; i++) {
                if (i >= coin) {
                    dp[i] += dp[i - coin];    
                }
            }
        }
        return dp[amount];
    }
}

In this problem, we are required to count the duplicate results. 
However, in coin change, 1 + 1 + 2 is the same with 1 + 2 + 1. 
The order of the for loop actually makes these two different problems. */
