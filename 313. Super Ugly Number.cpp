class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1) return 1;
        vector<int> v{0,1};
        vector<int> index(primes.size(), 1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >q;
        for(int i=0;i<primes.size(); i++) q.push({primes[i],i});
        for(int i=2;i<=n;i++)
        {
            int a=q.top().first;
            v.push_back(a);
            while(!q.empty() && q.top().first==a)
            {
                int j=q.top().second;
                index[j]++;
                q.push({primes[j]*v[index[j]], j});
                q.pop();
            }
        }
        return v[n];
    }
};
