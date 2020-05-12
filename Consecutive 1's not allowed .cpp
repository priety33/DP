#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    int dp[n+1];
	    dp[0]=1; dp[1]=2;
	    for(int i=2; i<=n; i++) dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
	    cout<<dp[n]%mod<<endl;
	}
	return 0;
}
