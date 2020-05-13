#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--)
    {
        int k, r, c;
        cin>>k>>r>>c;
        
        double dp[r+1][r+1];
        dp[1][1]=k;
        for(int i=2; i<=r; i++)
        {
            dp[i][1]= (dp[i-1][1]-1>0)? (dp[i-1][1]-1)/2.0 : 0.0;
            for(int j=2; j<i; j++)
            {
                double l=(dp[i-1][j-1]-1>0)? (dp[i-1][j-1]-1)/2.0 : 0.0;
                double r=(dp[i-1][j]-1>0)? (dp[i-1][j]-1)/2.0 : 0.0;
                dp[i][j]=l+r;
            }
            dp[i][i]=(dp[i-1][i-1]-1>0)? (dp[i-1][i-1]-1)/2.0 : 0.0;
        }
        double a= (dp[r][c]>1)? 1.0 : dp[r][c];
        cout<<a<<endl;
    }
	return 0;
}
