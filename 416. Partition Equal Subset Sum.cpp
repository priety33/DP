//1D bottom up Dp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        if(n==0) return false;
        int m=nums[0];
        for (auto num : nums){
            sum += num;
            m=max(m,num);
        }
        if ((sum & 1) == 1){
            return false;
        }
        if(sum%2!=0) return false;
        sum /= 2;
        if(sum<m) return false;
        bool dp[sum+1];
        memset(dp,false,sizeof(dp));
        dp[0] = true;
        for (auto num : nums){
            for (int i = sum; i > 0; i--){
                if (i >= num) {
                    dp[i] = dp[i] || dp[i-num];
                }
                if(dp[sum]) return true;
            }
        }
        return dp[sum];
    }
};

//2D top down dp (from recursion)
class Solution {
public:
    bool find(int s, vector<vector<int>> &dp, vector<int>& nums, int sum) {
        if (sum<0 || (s>=nums.size() && sum>0)){ 
            return false;
        }
        else if(sum-nums[s]==0){
             return dp[s][sum]=1;
        }
        if(dp[s][sum]!=-1) return dp[s][sum];
        
        //if sum can be made from array. starting at index s.
        dp[s][sum]= find(s+1, dp, nums, sum) || find(s+1, dp, nums, sum-nums[s]);
        return dp[s][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) 
            sum+=nums[i];
        if(sum%2!=0) return false;
        sum=sum/2;
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        find(0, dp, nums, sum);
        return dp[0][sum];
    }
};
