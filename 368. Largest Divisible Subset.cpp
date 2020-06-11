class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //sorting makes it easier to check for mod condition, because for a>b, b%a!=0 always,
        //therefore check for mod only with smaller nos., complexity = O(n^2 + nlogn)= O(n^2)=> sorting doesnt change complexity
        sort(nums.begin(), nums.end());
        int n=nums.size();
        if(n==0) return {};
        int count[n], parent[n];
        int len=0, index;
        for(int i=0; i<n; i++) {
            count[i]=0;
            parent[i]=0;
            for(int j=i; j>=0; j--) {
                if(nums[i]%nums[j]==0) {
                    if(1+count[j]>count[i]) {
                        count[i]= 1+count[j];
                        parent[i]=j;
                    }
                }
            }
            if(count[i]>len) {
                len=count[i], index=i;
            }
        }
        vector<int> ans;
        while(count[index]--) {
            ans.push_back(nums[index]);
            index=parent[index];
        }
        return ans;
    }
};
