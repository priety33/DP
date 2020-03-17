#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    int ans=0;
	    int a[n][m];
	    int dp[n][m]={0};
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cin>>a[i][j];
	            if(a[i][j]) ans=1;
	            if(i==0 || j==0) dp[i][j]=a[i][j];
	        }
	    }
	    for(int i=1;i<n;i++)
	    {
	        for(int j=1;j<m;j++)
	        {
	            if(a[i][j])
	            {
	                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
	                ans=max(ans,dp[i][j]);
	            }
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
