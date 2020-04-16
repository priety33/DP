class Solution {
public:
    bool divisorGame(int N) {
        int dp[N+1];
        for(int i=0;i<=N;i++) dp[i]=0;
        for(int i=2;i<=N;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(i%j==0 && dp[i-j]==0) // if second player loses starting from [i-j] => first wins starting from [i]
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[N];
    }
};

// dp[i]=1 => wins starting from here
// dp[i]=0 => loses if starting from here
