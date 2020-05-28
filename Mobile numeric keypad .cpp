#include <bits/stdc++.h>
using namespace std;

long long count(char keypad[][3], int n) {
    //dp[i][j] -> ways of forming j length sequence starting from digit i.
    long long dp[10][n+1];
    for(int i=0; i<10; i++) {
        dp[i][0]=0;
        dp[i][1]=1;
    }
    
    int row[]={0,-1,0,1,0};
    int col[]={0,0,-1,0,1};
    
    for(int len=2; len<=n; len++) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<3; j++) {
                if(keypad[i][j]!='*' && keypad[i][j]!='#') {
                    int num = keypad[i][j] - '0'; 
                    dp[num][len] = 0; 
                    for (int move=0; move<5; move++) 
                    { 
                        int ro = i + row[move]; 
                        int co = j + col[move]; 
                        if (ro >= 0 && ro <= 3 && co >=0 && co <= 2 && 
                           keypad[ro][co] != '*' && keypad[ro][co] != '#') 
                        { 
                            int nextNum = keypad[ro][co] - '0'; 
                            dp[num][len] += dp[nextNum][len-1]; 
                        } 
                    } 
                }
            }
        }
    }
    long long ans=0;
    for(int i=0; i<10; i++) ans+=dp[i][n];
    return ans;
}

int main() {
	int t; cin>>t;
	
	char keypad[4][3] = {{'1','2','3'}, 
                        {'4','5','6'}, 
                        {'7','8','9'}, 
                        {'*','0','#'}}; 
	
	while(t--) {
	    int n; cin>>n;
	    cout<<count(keypad,n)<<endl;
	}
	return 0;
}
