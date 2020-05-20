//recursive
int count(int s, int e, string str)
{
    if(e<s) return 0;
    
    if(s==e) return 1;
    else if(str[s]==str[e]) return 1+ count(s+1, e, str)+ count(s, e-1, str);
    return count(s+1, e, str)+ count(s, e-1, str) - count(s+1, e-1, str);
}

int countPS(string str)
{
   return count(0, str.length()-1, str);
}


//DP
int countPS(string str)
{
   int n=str.size();
   int dp[n][n];
   memset(dp, 0, sizeof(dp));
   for(int i=0;i<n;i++) dp[i][i]=1;
   for(int i=n-2; i>=0; i--)
   {
       for(int j=i+1; j<n; j++)
       {
           int a= dp[i+1][j];
           int b= dp[i][j-1];
           
           dp[i][j]= (str[i]==str[j])? 1+a+b : a+b-dp[i+1][j-1];
       }
   }
   return dp[0][n-1];
}
 
