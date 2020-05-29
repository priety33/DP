//DP
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int l, int m) {
        int n= A.size();
        int ps[n+1]; ps[0]=0;
        for(int i=1; i<=n; i++) ps[i]=ps[i-1]+A[i-1];
        //dpl= max sum of m sized subarray, int array(0 to i)
        int dpl[n], dpr[n];
        for(int i=0; i<n; i++) {
            if(i<m-1) dpl[i]=-1;
            else dpl[i]=max( (i==0) ? A[0] : dpl[i-1], ps[i+1]-ps[i+1-m]);
        }
        //dpl= max sum of m sized subarray, int array(i to n-1)
        for(int i=n-1; i>=0; i--) {
            if(i>n-m) dpr[i]=-1;
            else dpr[i]=max( (i==n-1)? A[n-1] : dpr[i+1], ps[i+m]-ps[i]);
        }
        int ans=ps[l]+dpr[l];
        for(int i=1; i<=n-l; i++) {
                                      //max msum on left     //max msum on right
            ans=max(ans, ps[i+l]-ps[i]+max(dpl[i-1], (i+l<n)? dpr[i+l] : -1));
        }
        return ans;
    }
};


//O(1)
/*
Lmax, max sum of contiguous L elements before the last M elements.
Mmax, max sum of contiguous M elements before the last L elements
*/
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        for (int i = 1; i < A.size(); ++i)
            A[i] += A[i - 1];
        int res = A[L + M - 1], Lmax = A[L - 1], Mmax = A[M - 1];
        for (int i = L + M; i < A.size(); ++i) {
            Lmax = max(Lmax, A[i - M] - A[i - L - M]);
            Mmax = max(Mmax, A[i - L] - A[i - L - M]);
            res = max(res, max(Lmax + A[i] - A[i - M], Mmax + A[i] - A[i - L]));
            cout<<Lmax<<" "<<Mmax<<endl;
        }
        return res;
    }
};
