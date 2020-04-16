class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        pair<int,int> dp[n][n];
        for(int i=0;i<n;i++) dp[i][i]={piles[i],0}; //dp[i][j].first= max value in subarray (i-j) first picker gets,
                                                    //dp[i][j].second=max value in subarray (i-j) second picker(picks after first player) gets
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1; j<n; j++)
            {
                int l=piles[i]+dp[i+1][j].second; //max value P1 can make, if picks leftmost item first => P1 will pick second in subarray (i+1,j), after P2 picks in it
                int r=piles[j]+dp[i][j-1].second; //max value P1 can make, if picks rightmost item first
                
                if(l>r)
                {
                    dp[i][j].first=l;
                    dp[i][j].second=dp[i+1][j].first;
                }
                else
                {
                    dp[i][j].first=r;
                    dp[i][j].second=dp[i][j-1].first;
                }
            }
        }
        return dp[0][n-1].first>dp[0][n-1].second;
    }
};
