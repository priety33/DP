/*
This problem is similar to Longest Increasing Subsequence problem. 
The difference is that we need to consider the arithmetic difference in this problem. How to keep track of the length 
as well as the difference? We can use a hashmap, whose key is the difference and value is the length. 
Then we can solve the problem with dynamic programming:

As noted in the problem description, 2 <= A.length, so we don't need to consider the edge case when there is no element
or only one element in A. The base case is A.length == 2, then A itself is the longest arithmetic subsequence 
because any two numbers meet the condition of arithmetic.
The optimization step is that for two elements A[i] and A[j] where i < j, the difference between A[j] and A[i] (name it diff)
is a critical condition. 
1. If the hashmap at position j has the key diff, it means that there is an arithmetic subsequence 
   ending at index j, with arithmetic difference diff and length dp[diff][j]. And we just add the length by 1. 
2. If hashmap does not have the key diff, then those two elements (i and j) can form a 2-length arithmetic subsequence.
   And update the result if necessary during the iteration.
*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n=A.size();
        if(n==2) return 2;
        int len=2;
        unordered_map<int, unordered_map<int,int>> dp; // dp[diff][i]= length of AP with d=diff, ending at i
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int d=A[j]-A[i];
                dp[d][j]= (dp[d][i]) ? dp[d][i]+1 : 2;
                len=max(len, dp[d][j]);
            }
        }
        return len;
    }
};
