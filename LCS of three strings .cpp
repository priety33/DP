#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n, m, o; cin>>n>>m>>o;
	    string a,b,c; cin>>a>>b>>c;
	    
	    int dp[n+1][m+1][o+1];
	    
	    for(int i=0; i<=n; i++) {
	        for(int j=0; j<=m; j++) {
	            for(int k=0; k<=o; k++) {
	                
	                if(i==0 || j==0 || k==0) dp[i][j][k]=0;
	                else if( a[i-1]==b[j-1] && b[j-1]==c[k-1]) dp[i][j][k]= 1 +dp[i-1][j-1][k-1];
	                else dp[i][j][k]= max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
	                
	            }
	        }
	    } 
	    
	    cout<<dp[n][m][o]<<endl;
	}
	return 0;
}
