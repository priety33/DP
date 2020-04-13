class Solution {
public:
    int integerBreak(int n) {
        vector<int> prod{0,1,1,2,4,6,9};
        if(n<prod.size()) return prod[n];
        for(int i=7;i<=n;i++)
        {
            int res=0;
            for(int j=i-1; j>=1;j--)
            {
                if( (i-j)*prod[j]>res ) res=(i-j)*prod[j];
            }
            prod.push_back(res);
        }
        return prod[n];
    }
};
