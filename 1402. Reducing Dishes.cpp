class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        int n=s.size();
        if(s[n-1]<=0) return 0;
        pair<int,int> dp[n][n];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]={1*s[i], 1};
            ans=max(ans, dp[i][i].first);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int a= dp[i][j-1].first, b=dp[i][j-1].second;
                dp[i][j]={a+ (b+1)*s[j], b+1};
                ans=max(ans, dp[i][j].first);
            }
        }
        return ans;
    }
};

//OR
class Solution {
public:
    int maxSatisfaction(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, total = 0, n = A.size();
        for (int i = n - 1; i >= 0 && A[i] > -total; --i) {
            total += A[i];
            res += total;
        }
        return res;
    }
};
