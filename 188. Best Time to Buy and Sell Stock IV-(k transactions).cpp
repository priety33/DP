class Solution {
public:
    
int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
    
    if(n == 0)
        return 0;
    
    if (k>n/2){// for n points, we can have max of n/2 local minima and maxima => buy at every local minima and sell at maxima
        int ans = 0;
        for (int i=1; i<n; ++i){
            ans += max(prices[i] - prices[i-1],0);
        }
        return ans;
    }
    
    vector<int> prev(n, 0);
    vector<int> curr(n, 0);
    
    for(int t = 1; t <= k; t++)
    {
        int max_so_far = INT_MIN;
        for(int d = 1; d < n; d++)
        {
            max_so_far = max(max_so_far, prev[d-1] - prices[d-1]); // factor taught in pep.
            curr[d] = max(curr[d-1], max_so_far + prices[d]); // 1. not making transaction today
                                                              // 2. making transaction today by considering max profit using 
                                                                    (t-1) transaction stored in prev.
        }
        swap(curr, prev);
    }
    
    return prev[n-1];
        
}
};
