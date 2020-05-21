/*
First, observe that there exists no solution where we can pick both slice 0 and slice n - 1,
which means that we can split the circular problem into 2 linear problems where we once pick slices from [0 ... n - 2] 
and then from [1 ... n - 1] (inclusive)

Basically, we want to choose the best way of selecting n / 3 slices such that no 2 slices are adjacent. 
Now for each slice, either we pick it or we do not. 
If we don't pick it, we are free to pick the one before it, else we must discard the one before it.

Hence, dp[i][j] is the best way to pick j slices among slices from [0 ... i - 2] or [1 ... i - 1] 
(depending on which of the two linear solutions we are currently handling, 
which is why you see slices[i - 1 - !a] in the solution)

a==0 => we are checking till i-2 in every subarray because we are including 0th element
a==1 => we are checking till i-1 in every subarray because we dont include 0 and hence can include last ie, i-1th element of subarray
*/

class Solution {
public:
    
    int slice(vector<int>& s, int a) {
        int n=s.size();
        vector<vector<int>> dp (n+2, vector<int>(n/3+1, 0));
        int ans=0;
        for(int i=2; i<n+2; i++) {
            for(int j=1; j<= n/3 ; j++)
            {
                dp[i][j]=max( dp[i-1][j], s[i-1-!a]+ dp[i-2][j-1]);
            }
        }
        return dp[n][n/3];
    }
    
    int maxSizeSlices(vector<int>& s) {
        return max( slice(s,0), slice(s,1));
    }
};
