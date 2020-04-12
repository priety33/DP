class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return 0;
        unordered_map<string,int> dic;
        for(int i=0;i<wordDict.size(); i++) dic[wordDict[i]]++;
        int n=s.size();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=n;i++) // i-> length of substring from 0.
        {
            if(!dp[i] && dic[s.substr(0,i)]) dp[i]=1; //finding first valid sunstring from start
            
            if(dp[i]) //found first valid substring -> find all valid substrings after this.
            {
                if(i==n) return true;
                
                for(int j=i+1; j<=n; j++)
                {
                    if(!dp[j] && dic[s.substr(i,j-i)]) dp[j]=1;
                    if(dp[j] && j==n) return true;
                }
            }
        }
        return dp[n];
    }
};
