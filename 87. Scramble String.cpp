//DP
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int sSize = s1.size(), len, i, j, k;
        if(0==sSize) return true;
        if(1==sSize) return s1==s2;
        bool isS[sSize+1][sSize][sSize];

        for(i=0; i<sSize; ++i)
            for(j=0; j<sSize; ++j)
                isS[1][i][j] = s1[i] == s2[j];
                
        for(len=2; len <=sSize; ++len)
            for(i=0; i<=sSize-len; ++i)
                for(j=0; j<=sSize-len; ++j)
                {
                    isS[len][i][j] = false; //is substring of length starting from i in s1, and j in s2 scramble?
                        for(k=1; k<len && !isS[len][i][j]; ++k)
                        {
                            isS[len][i][j] = isS[len][i][j] || (isS[k][i][j] && isS[len-k][i+k][j+k]); // s1: L-R, s2: L-R
                            isS[len][i][j] = isS[len][i][j] || (isS[k][i+len-k][j] && isS[len-k][i][j+k]); // s1: L-R, s2: R-L
                        }
                }
        return isS[sSize][0][0];            

    }
}; 

//RECURSION
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
            
        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }
        
        for(int i=1; i<=len-1; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
};
/*
For string of size n take time to be T(n) for it
We are starting from i=1 and going till n-1
This line of code isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
is T(i) + T(n-i)
and this line of code just below isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i))
is again T(i) + T(n-i)

So basically for T(n) we have:
T(n) = for i in 1 to n-1 : +2*(T(i) + T(n-i))
i.e.
T(n) = 2*(T(1) + T(n-1) + T(2) + T(n-2) + ... + T(n-1) + T(1)) ,
now we have two equal sequences T(1) to T(n-1) from left to right and T(n-1) to T(1) from right to left. So above equation can be written as
T(n) = 2 * 2(T(1) + T(2) + ...+ T(n-2) + T(n-1))
T(n) = 4 * (T(1) + T(2) + ...+ T(n-2) ) + 4 * T(n-1)

if we substitute n-1 in place of n above we get T(n-1) = 4 * (T(1) + T(2) + ...+ T(n-2) ) , using this in the above equation we get
T(n) = T(n-1) + 4 * T(n-1)
T(n) = 5 * T(n-1)

If we open this we get
T(n) = 5 * 5 * T(n-2) = 5 * 5 * 5 * T(n-3) = 5 * 5 * ... * 5 (n times)
so T(n) = O(5^n)
*/
