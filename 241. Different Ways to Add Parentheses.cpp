class Solution {
public:
    map<pair<int,int>, vector<int>> dp;
    
    vector<int> solve(vector<string> &v, int s, int e) {
        if(s==e) return {stoi(v[s])};
        if(dp.find({s,e})!=dp.end()) return dp[{s,e}];
        vector<int> a,b;
        vector<int> res;
        for(int k = s; k<e; k++)
        {
            if(v[k]=="+")
            {
                a = solve(v,s,k-1);
                b = solve(v,k+1,e);
                for(auto n1 : a)
                {
                    for(auto n2 : b)
                    {
                        res.push_back(n1+n2);
                    }
                }
            }
            if(v[k]=="-" )
            {
                a = solve(v,s,k-1);
                b = solve(v,k+1,e);
                for(auto n1 : a)
                {
                    for(auto n2 : b)
                    {
                        res.push_back(n1-n2);
                    }
                }
            }
            if(v[k]=="*")
            {
                a = solve(v,s,k-1);
                b = solve(v,k+1,e);
                for(auto n1 : a)
                {
                    for(auto n2 : b)
                    {
                        res.push_back(n1*n2);
                    }
                }
            }
        }
        return dp[{s,e}]=res;
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<string> v;
        string num="";
        for(int i=0; i<input.size(); i++) {
            if(isdigit(input[i])) num+=input[i];
            else {
                v.push_back(num);
                num="";
                v.push_back(num+input[i]);
            }
        }
        if(num!="") v.push_back(num);
        return solve(v, 0, v.size()-1);
    }
};
