class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        vector<int> v{0,1};
        int two=1, three=1, five=1;
        for(int i=1;i<=n;i++)
        {
            int a=min(2*v[two], min(3*v[three], 5*v[five]));
            v.push_back(a);
            if(a==2*v[two]) two++;
            if(a==3*v[three]) three++;
            if(a==5*v[five]) five++;
        }
        return v[n];
    }
};
