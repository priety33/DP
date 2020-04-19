/*
    If we sort all the numbers into buckets indexed by these numbers, 
    this is essentially asking you to repetitively take a bucket while giving up the 2 buckets next to it. -> similar to house robber
    (the range of these numbers is [1, 10000])

    The optimal final result can be derived by keep updating 2 variables skip_i, take_i, which stands for:
    skip_i : the best result for sub-problem of first (i+1) buckets from 0 to i, while you skip the ith bucket.
    take_i : the best result for sub-problem of first (i+1) buckets from 0 to i, while you take the ith bucket.

    DP formula:
    take[i] = skip[i-1] + values[i];
    skip[i] = Math.max(skip[i-1], take[i-1]);
    take[i] can only be derived from: if you skipped the [i-1]th bucket, and you take bucket[i].
    skip[i] though, can be derived from either take[i-1] or skip[i-1], whatever the bigger;

/**
 * for numbers from [1 - 10000], each has a total sum sums[i]; if you earn sums[i], you cannot earn sums[i-1] and sums[i+1]
 * kind of like house robbing. you cannot rob 2 connected houses.
 * 
 
*/


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001; //max val of nums[i]
        vector<int> value(n, 0);
        for(int i=0; i<nums.size(); i++) value[nums[i]]+= nums[i];
        
        int take=0, skip=0;
        for(int i=0; i<n; i++)
        {
            int takei= value[i]+ skip;
            int skipi= max(take, skip);
            
            take=takei;
            skip=skipi;
        }
        return max(take, skip);
    }
}; 


//starting from back and using dp array
//optimisation= finding max element in array, so now you dont have to traverse till 10001 (n)

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int count[10001] = {0};
        int dp[10001] = {0};
        int maxele = 0;
        for(auto& i : nums){
            count[i]++;
            maxele = max(i,maxele);
        }
        for(int i = maxele ; i > 0 ; i--){
            int t = count[i]*i;
            if(i+2 <= maxele){ //skipping i+1
                t += dp[i+2];
            }
            if(i+1 <= maxele){
                t = max(t, dp[i+1]); // including i, excluding i
            }
            dp[i] = t;
        }
        return dp[1];
    }
};
