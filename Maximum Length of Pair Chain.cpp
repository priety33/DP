/*
The idea is that this problem is basically asking to find the maximum number of non-overlapping intervals. 
The solution for this problem is to sort all intervals by earliest finishing time, and then start with the first interval,
find the the next interval with start that is higher than end of first interval, save the end of that interval,
find the next interval with start higher than this end, etc. until the last interval is visited. 
This algorithm is one of those "well known" algorithms like LCS, sliding windows, etc. that you should probably remember.
    

 1.   sort the pairs by their end in increasing order;
 2.   at any point, choose the pair that start after the tail end, then use it as the new tail;

*/
class Solution {
public:
    
    static bool compare(vector<int> a, vector<int> b)
    {
        return a[1]<b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        if(n==0) return 0;
        sort(pairs.begin(), pairs.end(), compare);
        int len=0, tail=INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(i==0 || pairs[i][0]>tail)
            {
                len++;
                tail=pairs[i][1];
            }
        }
        return len;
    }
};

//O(n2)
class Solution {
public:
    
    static bool compare(vector<int> a, vector<int> b)
    {
        return a[0]<b[0];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        if(n==0) return 0;
        sort(pairs.begin(), pairs.end(), compare);
        vector<int> dp(n, 1);
        int len=1;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(pairs[j][1]<pairs[i][0] && dp[j]+1>dp[i]) dp[i]=dp[j]+1;
                len=max(len, dp[i]);
            }
        }
        return len;
    }
};
