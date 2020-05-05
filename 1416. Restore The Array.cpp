class Solution {
public:
    
    #define mod 1000000007
    #define ll long long int 
    
    int numberOfArrays(string s, int k) {
        int n=s.length();
        ll dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[n]=1;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]!='0')
            {
                if(s[i]-'0'<k) dp[i]=dp[i+1]%mod;
                long long num = s[i]-'0';
                for(int j=i+1; j<n; j++)
                {
                    num=num*10+(s[j]-'0');
                    if(num>k) break;
                    dp[i]+=dp[j+1]%mod;
                }
            }
        }
        return dp[0]%mod;
    }
};
