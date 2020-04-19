class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        if(target > d*f) return 0;
        
        vector<vector<int>> dp(d+1, vector<int>(f*d+1, 0));
        for(int j=1; j<=f; j++) dp[1][j]=1; // one dice
        for(int i=1; i<=d; i++) dp[i][i]=1; // target=1
        
        for(int i=2; i<=d; i++) //number of dice
        {
            for(int j=i+1; j<=i*f; j++) //sum => max sum can be number of dice * faces => j<=i*f
            {
                for(int k=1; k<j && k<=f; k++)
                {
                    dp[i][j]= (dp[i][j]+ dp[i-1][j-k]) % 1000000007;
                }
            }
        }
        return dp[d][target];
    }
};
