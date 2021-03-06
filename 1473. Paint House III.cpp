//BACKTRACKING- half cases fail
class Solution {
public:
    
    int rec(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int neigh, int s, int ans) {
        if(neigh>target) return INT_MAX;
        if(s==m) {
            if(target==neigh) return ans;
            return INT_MAX;
        }
        // painted last year.
        if(houses[s]!=0) {
            if(s==0 || houses[s]!=houses[s-1]) return rec(houses, cost, m, n, target, neigh+1, s+1, ans);
            return rec(houses, cost, m, n, target, neigh, s+1, ans);
        }
        int c=INT_MAX;
        for(int i=0; i<n; i++) {
            houses[s]=i+1;
            if(s==0 || houses[s]!=houses[s-1]) c= min(c, rec(houses, cost, m, n, target, neigh+1, s+1, ans+cost[s][i]));
            else c=min(c, rec(houses, cost, m, n, target, neigh, s+1, ans+cost[s][i]));
            houses[s]=0;
        }
        return c;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int res=rec(houses, cost, m, n, target, 0, 0, 0);
        return (res==INT_MAX)? -1 : res;
    }
};


//DP
class Solution {
public:
    /*dp[i][j][k] as the minimum cost where we have j neighborhoods in the first i houses and the i-th house is painted with the color k*/
    int dp[101][101][21] = {};
    
    int rec(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int neigh, int s, int last_clr) {
        if(neigh>target) return 1000001;
        if(s>=m) {
            if(neigh==target) return 0;
            return 1000001;
        }
        // painted last year.
        if(houses[s]!=0) {
            if(s==0 || houses[s]!=last_clr) return rec(houses, cost, m, n, target, neigh+1, s+1, houses[s]);
            return rec(houses, cost, m, n, target, neigh, s+1, houses[s]);
        }
        if (dp[s][neigh][last_clr]) return dp[s][neigh][last_clr];
        int c=1000001;
        for(int clr=0; clr<n; clr++) {
            if(s==0 || last_clr!=clr+1) c= min(c, cost[s][clr] + rec(houses, cost, m, n, target, neigh+1, s+1, clr+1));
            else c= min(c, cost[s][clr] + rec(houses, cost, m, n, target, neigh, s+1, clr+1));
        }
        return dp[s][neigh][last_clr]=c;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int res = rec(houses, cost, m, n, target, 0, 0, 0);
        return (res>1000000)? -1 : res;
    }
};
