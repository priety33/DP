//RECURSION- fails in longer test cases

class Solution {
public:
    
    vector<string> ans;
    
    void sentence(map<string,bool> dict, string s, int n, string res)
    {
        for(int i=1; i<=n; i++)
        {
            string a= s.substr(0,i);
            if(dict[a])
            {
                if(i==n)
                {
                    res+=a;
                    ans.push_back(res);
                    return;
                }
                sentence(dict, s.substr(i,n-i), n-i, res+a+" ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return ans;
        
        map<string, bool> dict;
        for(int i=0; i<wordDict.size(); i++) dict[wordDict[i]]=true;
        
        sentence(dict, s, s.size(), "");
        return ans;
    }
};


/*
wordDict = ["cat", "cats", "and", "sand", "dog"]
index:    0   1   2   3   4   5   6   7   8   9
        +---------------------------------------+
s:      | c | a | t | s | a | n | d | d | o | g |
        +---------------------------------------+
          i   
          j

dp[0] = []
dp[1] = []
dp[2] = ["cat"]
dp[3] = ["cats"]
dp[4] = []
dp[5] = []
dp[6] = ["cat sand","cats and"]
dp[7] = []
dp[8] = []
dp[9] = ["cat sand dog","cats and dog"]

>> recurrence relation:
dp[i] = 
for (int j = 0; j < i; j++) {
	substr = s[j, i];
  if (dp[j].size() > 0 && wordDict.contains(substr)) {
      for (String l : dp[j]) {
          dp[i].add(l + substr);
      }
  }
}
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int N = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        vector<vector<string>> dp(N + 1, vector<string>());
        dp[0].push_back("");
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                string substr = s.substr(j, i - j + 1);
                if(dp[j].size() > 0 && wordSet.find(substr) != wordSet.end()){
                    for(string& l : dp[j]){
                        dp[i+1].push_back(l + (l == "" ? "" : " ") + substr);
                    }
                }
            }
        }
        
        return dp[N];
    }
};


//more optimised DP

class Solution {
public:
    
    vector<string> ans;
    
    void getpath(map<string, bool> dict, bool isbreakable[], string s, int pos, int l, int minlen, int maxlen, string res)
    {
        for(int i=minlen; i<=min(maxlen, l-pos); i++)
        {
            if(isbreakable[pos+i] && dict[s.substr(pos,i)]) //can be broken here only if
                                                            //1. word just after this is valid (isbreakable[pos+i])
                                                            //2. this word is valid 
            {
                if(pos+i==l) ans.push_back(res+s.substr(pos,i)); //whole string covered
                else getpath(dict, isbreakable, s, pos+i, l, minlen, maxlen, res+s.substr(pos,i)+" ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int l=s.size();
        if(wordDict.size()==0) return ans;
        map<string, bool> dict;
        for(int i=0; i<wordDict.size(); i++) dict[wordDict[i]]=true;
        
        int minlen=INT_MAX, maxlen=INT_MIN;
        for(int i=0;i<wordDict.size(); i++)
        {
            minlen= min(minlen, (int)wordDict[i].length());
            maxlen= max(maxlen, (int)wordDict[i].length());
        }
        
        bool isbreakable[l+1]; //DP to store indexes from where valid words start
        memset(isbreakable, 0, sizeof(isbreakable));
        isbreakable[l]=1;
        for(int i=l-minlen; i>=0; i--)
        {
            for(int len=minlen; len<= min(maxlen, l-i); len++)
            {
                if(isbreakable[i+len] && dict[s.substr(i,len)])
                {
                    isbreakable[i]=1;
                    break;
                }
            }
        }
        //if string is breakable, do dfs path finding.
        if(isbreakable[0]) getpath(dict, isbreakable, s, 0, l, minlen, maxlen, "");
        return ans;
    }
};
