#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        int price[n], weight[n];
        for(int i=0;i<n;i++) cin>>price[i];
        for(int i=0;i<n;i++) cin>> weight[i];
        
        int dp[n][w+1];
        for(int i=0;i<n;i++) dp[i][0]=0;
        for(int j=1;j<=w;j++)
        {
            dp[0][j]= (weight[0]>j)? 0:price[0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=w; j++)
            {
                if(weight[i]>j) dp[i][j]=dp[i-1][j];
                else
                {
                    dp[i][j]=max( price[i]+ dp[i-1][j-weight[i]], dp[i-1][j]); // including, excluding
                }
            }
        }
        cout<<dp[n-1][w]<<endl;
    }
}
