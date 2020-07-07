class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        // W[i]= subarray size k sum starting at nums[i]
        vector<int> W(n, 0);
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            if (i >= k) {
                currSum -= nums[i - k];
            }
            if (i >= k - 1) {
                W[i - k + 1] = currSum;
            }
        }

        int left[n]; //maximum sum index, subarray ending at nums[i]
        int best = 0;
        for (int i = 0; i < n; i++) {
            if (W[i] > W[best]) best = i;
            left[i] = best;
        }

        int right[n]; //maximum sum index, subarray starting at nums[i]
        best = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (W[i] >= W[best]) best = i;
            right[i] = best;
        }
        
        vector<int> ans= {-1,-1,-1};
        for (int j = k; j < n - k; j++) {
            int i = left[j - k], l = right[j + k];
            if (ans[0] == -1 || W[i] + W[j] + W[l] > W[ans[0]] + W[ans[1]] + W[ans[2]]) {
                ans[0] = i;
                ans[1] = j;
                ans[2] = l;
            }
        }
        return ans;
    }
};
