/*
    Space : * O(mask * hat) : O((2 ^10) * 40) = O(1024 * 10)
    Time : O(hats * mask * people_holding_that_hat) : O(40 * (2 ^10) * 10)
*/
class Solution {
public:
    
    #define MOD 1000000007
    #define ll long long
    
    int all_people;
    vector<vector<int>> hat;
    vector<vector<ll>> dp;
    
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        all_people= (1<<n)-1;
        dp.resize(1025, vector<ll>(41, -1)), hat.resize(41);
        for(int i=0;i<n;i++)
        {
            for(int j: hats[i]) hat[j].push_back(i);
        }
        return helper(0,1) % MOD;
    }
    
    ll helper(int mask, int hid)
    {
        if(mask==all_people) return 1;
        if(hid==41) return 0;
        if(dp[mask][hid]!=-1) return dp[mask][hid];
        
        ll ans=0;
        
        ans= helper(mask, hid+1) % MOD;
        
        for(int p: hat[hid])
        {
            if( (mask&(1<<p))==0 )
            {
                ans+= (helper( (mask|(1<<p)), hid+1 ) % MOD);
            }
        }
        dp[mask][hid]=ans;
        return ans;
    }
    
};
