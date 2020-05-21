// bfs

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> s;
        map<pair<int,int>, bool>visited; //checks if <stone> is visited in <k> jumps.
        for(int i=0; i<stones.size(); i++) {
            s[stones[i]]=true;
        }
        int ans=stones[stones.size()-1];
        queue<vector<int>> q;
        if(s.find(1)==s.end()) return false;
        q.push({1,1});
        visited[{1,1}]=true;
        while(!q.empty()) {
            int x=q.front()[0];
            int k=q.front()[1];
            q.pop();
            if(x==ans) return true;
            if(k-1>0 && s.find(x+k-1)!=s.end() && !visited[{x+k-1, k-1}]) {
                q.push({x+k-1, k-1});
                visited[{x+k-1, k-1}]=true;
            }
            if(s.find(x+k)!=s.end() && !visited[{x+k, k}]) {
                q.push({x+k, k});
                visited[{x+k, k}]=true;
            }
            if(s.find(x+k+1)!=s.end() && !visited[{x+k+1, k+1}]) {
                q.push({x+k+1, k+1});
                visited[{x+k+1, k+1}]=true;
            }
        }
        return false;
    }
};


//DP= let dp[i][j] denote at stone i, the frog can or cannot make jump of size j

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        dp[0][1]=1;
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int dis= stones[i]-stones[j]; //finding previous jump to make a jump of j, from i.
                if(dis<0 || dis>n || !dp[j][dis]) continue;
                if(dis-1>=0) dp[i][dis-1]=1;
                dp[i][dis]=1;
                if(dis+1<=n) dp[i][dis+1]=1;
                if(i==n-1) return true; //we can only jump from stone i, after reaching stone i.
            }
        }
        return false;
    }
};
