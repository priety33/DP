//LIS

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int sum[n];
	    sum[0]=a[0];
	    int maxs=a[0];
	    for(int i=1;i<n;i++)
	    {
	        sum[i]=a[i];
	        for(int j=0;j<i;j++)
	        {
	            if(a[j]<a[i] && sum[j]+a[i]>sum[i]) sum[i]=sum[j]+a[i];
	        }
	        maxs=max(maxs,sum[i]);
	    }
	    cout<<maxs<<endl;
	}
	return 0;
}

//O(nlogn)- similar to activity selection problem, greedy

bool comp(struct val a,struct val b){
    return a.second < b.second;
}
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
