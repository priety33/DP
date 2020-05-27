//bfs- takes longer time -tle
class Solution {
public:
    int minSteps(int n) {
        string a="A";
        unordered_map<string,string>visited;
        visited[a]="";
        queue<tuple<string,string,int>>q;
        q.push({a,"",0});
        while(!q.empty()) {
            a= get<0>(q.front());
            string copy= get<1>(q.front());
            int steps= get<2>(q.front());
            q.pop();
            if(a.length()==n) return steps;
            if(a.length()>n) continue;
            if(visited[a+copy]!=copy) {
                q.push({a+copy,copy,steps+1});
                visited[a+copy]=copy;
            }
            if(visited[a]!=a) {
                q.push({a,a,steps+1});
                visited[a]=a;
            }
        }
        return 0;
    }
};

//DP
class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        int dp[n+1];
        dp[0]=0; dp[1]=0; dp[2]=2;
        for(int i=3; i<=n; i++) {
            int j=i/2;
            while(i%j!=0) j--;
            int x=j, m=0;
            while(x!=i) {
                x+=j;
                m++;
            }
            dp[i]= dp[j]+1+m;
        }
        return dp[n];
    }
};

//without DP
class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        for (int i = 2; i < n; i++)
            if (n % i == 0) return i + minSteps(n / i);
        return n;
    }
};
