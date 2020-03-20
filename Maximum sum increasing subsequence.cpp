//LIS

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int sum[n];
	    sum[0]=a[0];
	    int maxs=a[0];
	    for(int i=1;i<n;i++)
	    {
	        sum[i]=a[i];
	        for(int j=0;j<i;j++)
	        {
	            if(a[j]<a[i] && sum[j]+a[i]>sum[i]) sum[i]=sum[j]+a[i];
	        }
	        maxs=max(maxs,sum[i]);
	    }
	    cout<<maxs<<endl;
	}
	return 0;
}
