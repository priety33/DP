class Solution {
public:
    
    int get(int a, unordered_map<int, int> &dp)
    {
        if(a==1) return 0;
        if(dp.find(a)!=dp.end()) return dp[a];
        
        if(a%2==0) dp[a]=1+ get(a/2 ,dp);
        else dp[a]=1+ get(3*a+1 ,dp);
        
        return dp[a];
    }
    
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> dp;
        dp[1]=0;
        for(int i=lo; i<=hi; i++) get(i, dp);
        int n=hi-lo+1;
        vector<pair<int,int>> v;
        for(int i=lo; i<=hi; i++) v.push_back({dp[i], i});
        sort(v.begin(),v.end()); //automatically sorts vector of ints, pairs.
        return v[k-1].second;
    }
};
