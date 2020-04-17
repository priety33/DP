class Solution {
public:
    
    static bool compare( string a, string b)
    {
        return a.length() < b.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        if(n==1) return 1;
        
        unordered_map< string, int> dp; //will store max length of chain till this word => we will sort array words and move from smallest string to largest
        for(int i=0;i<n;i++) dp[words[i]]=1;
        
        sort(words.begin(), words.end(), compare);
        int len=1, minlen=words[0].length();
        for(int i=0; i<n; i++)
        {
            int l=words[i].size();
            if(l>minlen)
            {
                for(int j=0; j<l; j++) //considering all substrings with one char less
                {
                    string p="";
                    if(j==0) p=words[i].substr(1, l-1);
                    else if(j==l-1) p=words[i].substr(0,l-1);
                    else p= words[i].substr(0,j)+ words[i].substr(j+1, l-1-j);
                    
                    if(dp.find(p)!=dp.end()) dp[words[i]]=max( dp[words[i]], dp[p]+1);
                }
                len=max(len, dp[words[i]]);
            }
        }
        return len;
    }
};
