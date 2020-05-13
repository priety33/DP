#include <bits/stdc++.h>
using namespace std;

bool inside(int x, int y, int n)
{
    return x>=0 && x<n && y>=0 && y<n;
}

double find(int n, int x, int y, int k)
{
    //dp[x][y][steps] = probability of reaching (x,y) after (steps) number of moves
    double dp[n][n][k+1];
    
    static int r[]={-2,-2,-1,1,2,2,-1,1};
    static int c[]={-1,1,-2,-2,-1,1,2,2};
    
    //in 0 steps, it will always be inside => prob=1
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) dp[i][j][0]=1.0;
    }
    
    for(int step=1; step<=k; step++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                double prob=0.0;
                
                for(int k=0; k<8; k++)
                {
                    if(inside(i+r[k], j+c[k], n)) prob+= dp[i+r[k]][j+c[k]][step-1]/8.0;
                }
                
                dp[i][j][step]=prob;
            }
        }
    }
    
    return dp[x][y][k];
}

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n, x, y, k;
	    cin>>n>>x>>y>>k;
	    double a=find(n, x, y, k);
	    printf("%.6lf", a);
	    cout<<endl;
	}
	return 0;
}
