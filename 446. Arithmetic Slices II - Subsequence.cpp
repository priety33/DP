#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size(), ans=0;
        vector<map<ll, int>> cnt(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                long long d= (ll)a[i]-(ll)a[j];
                int count=0;
                if(cnt[j].find(d)!=cnt[j].end()) {
                    count= cnt[j][d];
                }
                cnt[i][d]+= count+1;
                ans+= count;
            }
        }
        return ans;
    }
};
