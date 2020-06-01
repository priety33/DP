//BACKTRACKING _ TLE
class Solution {
public:
    int ans= INT_MAX;
    vector<vector<int>> v{{0,0},{ 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 }};
    
    bool possible(int i, int j, const int n, const int m, vector<vector<int>>& visited) {
        return i>=0 && j>=0 && i<n && j<m && !visited[i][j];
    }
    
    void solve(int row, int col, const int n, const int m, vector<vector<int>>& g, vector<vector<int>>& visited, int cost) {
        if(row==n-1 && col==m-1) {
            ans=min(ans, cost);
            return ;
        }
        for(int k=1; k<=4; k++) {
            if(possible(row+v[k][0], col+v[k][1], n, m, visited)) {
                
                if(k!=g[row][col]) {
                    visited[row+v[k][0]][col+v[k][1]]=1;
                    solve(row+v[k][0],col+v[k][1],n, m, g, visited, cost+1);
                    visited[row+v[k][0]][col+v[k][1]]=0;
                 }
                else solve(row+v[k][0],col+v[k][1],n, m, g, visited, cost);
        }
    } }
    
    int minCost(vector<vector<int>>& grid) {
        int n= grid.size(), m=grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[0][0]=1;
        solve(0, 0, n, m, grid, visited, 0);
        return ans;
    }
};

//DP
//dp[i][j] -> min changes required from grid[i][j] to reach dp[i][j]
//Within the loop, we first go left or up and record the min steps to the (0,0), 
//then we go right or down to (m-1,n-1) -> because smaller change path can be obtained by merging in the path from right or down.
//We repeat until the DP matrix remains the same -> run this [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
//The time complexity is O((m+n)mn), because we need to change O(m+n) signs to get a valid path in the worst case. 
//The space complexity is O(mn).
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 10000));
        dp[m-1][n-1] = 0;
        
        while (true) {
            vector<vector<int>> temp(dp);
            for(int i=m-1; i>=0; i--) {
                for(int j=n-1; j>=0; j--) {
                    dp[i][j]= min(dp[i][j], min ( (j+1<n)? (grid[i][j] == 1 ? dp[i][j+1] : 1+dp[i][j+1] ) : 10000,
                                                  (i+1<m)? (grid[i][j] == 3 ? dp[i+1][j] : 1+dp[i+1][j] ) : 10000));
                }
            }
            if(temp==dp) break;
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    dp[i][j]= min(dp[i][j], min ( (j)? (grid[i][j] == 2 ? dp[i][j-1] : 1+dp[i][j-1] ) : 10000,
                                                  (i)? (grid[i][j] == 4 ? dp[i-1][j] : 1+dp[i-1][j] ) : 10000));
                }
            }
        }
        
        return dp[0][0];
    }
};

//bfs, graph solution also possible, see graph repo.
