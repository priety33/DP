class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int dp[n][n];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(j>i)
                {
                    dp[i][j]=INT_MIN;
                    for(int k=i;k<=j;k++) //k is the last balloon in subarray i-j
                    {
                        int left=0, l=1, right=0, r=1;
                        
                        if(k>i) left=dp[i][k-1]; //max value achieved from subarray left of k
                        if(k<j) right=dp[k+1][j];//max value achieved from subarray right of k
                        
                        if(i>0) l=nums[i-1];  
                        if(j<n-1) r=nums[j+1];
                        dp[i][j]=max(dp[i][j], left+right+ l*nums[k]*r);
                    }
                }
                else if(j==i)
                {
                    int l=1, r=1;
                    if(i>0) l=nums[i-1];
                    if(j<n-1) r=nums[j+1];
                    dp[i][j]=l*nums[i]*r;
                }
            }
        }
        return dp[0][n-1];
    }
};
