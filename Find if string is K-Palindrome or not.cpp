#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    int n; cin>>n; int k; cin>>k;
	    string s; cin>>s;
      //dp[i][j]= deletion needed to make substring(i-j) palindromic
	    int dp[n][n];
	    memset(dp, 0, sizeof(dp));
	    for(int i=n-2; i>=0; i--) {
	        for(int j=i+1; j<n; j++) {
	            if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
	            else dp[i][j]= 1+ min(dp[i+1][j], dp[i][j-1]);
	        }
	    }
	    int ans= (dp[0][n-1]<=k)? 1 : 0;
	    cout<<ans<<endl;
	}
	return 0;
}
