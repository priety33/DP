class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        long long dp[n+1];
        dp[0]=0;
        dp[1]=0;
        
        //in this loop, dp[i] will store count of numbers(i digit) with repetitive digits
        for(int i=2;i<=n;i++)
        {
            dp[i]= (9*pow(10,i-2))*(i-1)   +   dp[i-1]*(11-i);
            
          /* 1.                  dp[i-1] * (i-1)
              count of(i-1)digit numbers * for (i-1)digit no=> to make it i digit non repetative, (i-1)digits cant be appended
             2. dp[i-1]=> already repetitive numbers* from (0-9) 10 possibilities,
             i-1 are added in 1. add rest(10-(i-1))=11-i here  */
        }
        
        //this loop will store total count of repetitice digits till 10^i
        for(int i=1;i<=n;i++)
        {
            dp[i]+=dp[i-1];
        }
        return pow(10,n)-dp[n];
    }
};
