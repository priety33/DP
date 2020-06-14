class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size(), sum=0;
        unordered_map<int, int > ps;
        ps[0]=0;
        int len= INT_MAX, ans=INT_MAX;
        vector<int> minlen;
        minlen.push_back(INT_MAX);
        for(int i=0; i<n; i++) {
            int curlen=INT_MAX;
            sum+= arr[i];
            if(ps.find(sum-target)!=ps.end()) {
                curlen= i+1-ps[sum-target];
                len=min(len, curlen);
                if(minlen[ps[sum-target]]!=INT_MAX) ans=min(ans, curlen+ minlen[ps[sum-target]]);
            }
            ps[sum]=i+1;
            minlen.push_back(len);
        }
        return (ans==INT_MAX)? -1 : ans;
    }
};
