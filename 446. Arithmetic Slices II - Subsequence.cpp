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
                    count= cnt[j][d]; //number of sequences of length>2
                }
                cnt[i][d]+= count+1; //when count=0, we form a sequence of two elements-> a[j],a[i], and thus add 1 for this                         //sequence ending at a[i], because elements after i when added to this sequence can make a valid 3 length sequence.
                ans+= count;
                //only count is added to ans, (if 2 len sequence, count=0)
            }
        }
        return ans;
    }
};
//this program calculates number of sequnce of length>=3
//for length=1, add n.
//for length=2, any 2 elements can form an AP of 2 length=> add all possible pairs
//add 1 if emoty sequence is to be considered
