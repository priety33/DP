// 2d DP- O(n^2)
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>>n;
	    int a[n]; for(int i=0;i<n;i++) cin>>a[i];
	    cin>>k;
	    
	    int ans=INT_MIN;
	    int dp[n][n];
	    for(int i=0;i<n;i++)
	    {
	        dp[i][i]=a[i];
	        if(k==1) ans=max(ans, dp[i][i]);
	    }
	    for(int i=n-2; i>=0; i--)
	    {
	        for(int j=i+1; j<n; j++)
	        {
	            dp[i][j]=dp[i][j-1]+a[j];
	            if(j-i+1>=k) ans=max(ans,dp[i][j]);
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}


// 1d- prefix sum- O(n)
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>>n;
	    int a[n]; for(int i=0;i<n;i++) cin>>a[i];
	    cin>>k;
	    
	    int max_sum[n];
	    max_sum[0]=a[0];
	    for(int i=1;i<n;i++) max_sum[i]=max(a[i], a[i]+max_sum[i-1]); //storing maximum possible sum till a[i]
	    
	    int sum=0;
	    for(int i=0;i<k;i++) sum+=a[i]; //sliding window size k, sum
	    
	    int res=sum;
	    for(int i=k; i<n; i++)
	    {
	        sum= sum+a[i]-a[i-k]; //sum of k sized window ending at a[k]
	        res=max(res, sum);
	        res=max(res, sum+max_sum[i-k]); //can sum increase if we add maximum possible sum befor this window?
	    }
	    cout<<res<<endl;
	}
	return 0;
}
