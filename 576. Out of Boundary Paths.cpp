class Solution {
public:
    
    #define mod 1000000007
    
    int findPaths(int m, int n, int N, int x, int y) {
        int dp[m][n][N+1];
        memset(dp, 0, sizeof(dp));
        int r[4]= {0,-1,0,1};
        int c[4]= {-1,0,1,0};
        for(int k=1; k<=N; k++) {
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    int out=0;
                    for(int p=0; p<4; p++) {
                        if(i+r[p]<0 || j+c[p]<0 || i+r[p]==m || j+c[p]==n) out++;
                        else dp[i][j][k]=(dp[i][j][k]%mod+dp[i+r[p]][j+c[p]][k-1]%mod)%mod;
                    }
                    dp[i][j][k]=(dp[i][j][k]%mod+out%mod)%mod;
                }
            }
        }
        return dp[x][y][N]%mod;
    }
};
