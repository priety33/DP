 =>  O(ns) pseudo polynomial dp, s is the target sum. Most dp problems visits continuous states and this is a great example to use hashtable to visit valid states only.

    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        dp[0][0]=1;
        for(int i=0;i<n;i++)
            for(auto &p:dp[i]) {
                dp[i+1][p.first+nums[i]] += p.second; 
                dp[i+1][p.first-nums[i]] += p.second;
            }
        return dp[n][S];
    }

  => O(ns) time, linear space dp.

    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int,int> cur({{0,1}}), nxt, *p_cur=&cur, *p_nxt=&nxt;
        for(int i=0;i<nums.size();i++) {
            for(auto &p:*p_cur) {
                (*p_nxt)[p.first+nums[i]] += p.second; 
                (*p_nxt)[p.first-nums[i]] += p.second;
            }
            swap(p_cur,p_nxt);
            p_nxt->clear();
        }
        return (*p_cur)[S];
    }
