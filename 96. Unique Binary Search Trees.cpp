class Solution {
public:
    //catalans number
    
    long long coeff(int n, int k)
    {
        if(k>n-k) k=n-k;
        long long res=1;
        for(int i=0;i<k;i++)
        {
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }
    
    int numTrees(int n) {
        return coeff(2*n,n)/(n+1);
    }
};
