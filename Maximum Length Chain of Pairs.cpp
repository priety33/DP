//https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/

#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};

bool compare(struct val a, struct val b)
{
    if(a.first!=b.first) return a.first<b.first;
    return a.second<b.second;
}

//O(n2)-LIS
int maxChainLen(struct val a[],int n)
{
   sort(a,a+n,compare);
   int lis[n];
   lis[0]=1;
   int maxl=1;
   for(int i=1;i<n;i++)
   {
       lis[i]=1;
       for(int j=0;j<i;j++)
       {
           if(a[j].second<a[i].first && lis[j]+1>lis[i]) lis[i]=lis[j]+1;
       }
       maxl=max(maxl,lis[i]);
   }
   return maxl;
}

O(nlogn)-similar to activity selection
int maxChainLen(struct val vect[],int n){
   if(n==0)return 0;
   
    int ans=1;
    sort(vect,vect+n,comp);
    int b=vect[0].second;
    for(int i=1;i<n;i++){
        // Condition for Compatibilty
        if(b < vect[i].first){
            b=vect[i].second;
            ans++;
        }
    }
    return ans;
}    

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
