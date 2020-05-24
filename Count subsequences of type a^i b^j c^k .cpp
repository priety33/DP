#include <iostream>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    string s; cin>>s;
	    int dp[3]={0}; //dp[0]- string ending with a, dp[1]= string ending with b, dp[2]- string ending with c
	    for(int i=0;i<s.length();i++)
	    {
	        if(s[i]=='a') {
	            dp[0]= 1+2*dp[0]; 
	        }
	        else if(s[i]=='b') {
	            dp[1]= dp[0]+ 2*dp[1]; //string ending with a + 2* string ending with b
	        }
	        else dp[2]= dp[1]+ 2*dp[2]; //string ending with b + 2* string ending with c
	    }
	    cout<<dp[2]<<endl;
	}
	return 0;
}
