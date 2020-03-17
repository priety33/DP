//https://www.codechef.com/problems/REVERSE

#include <bits/stdc++.h>
using namespace std;

int main() {
	int v,e;
	cin>>v>>e;
	int ** edge= new int*[v];
	for(int i=0;i<v;i++)
	{
	    edge[i]=new int[v];
	}
	for(int i=0;i<v;i++)
	{
	    for(int j=0;j<v;j++)
	    {
	        edge[i][j]=-1;
	    }
	}
	for(int i=0;i<e;i++)
	{
	    int x,y;
	    cin>>x>>y;
	    edge[x-1][y-1]=0;
	    edge[y-1][x-1]=1;
	}
	int dis[v];
	bool vis[v];
	for(int i=0;i<v;i++) 
	{
	    dis[i]=INT_MAX;
	    vis[i]=false;
	}
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >q;
	q.push(make_pair(0,0));
	while(!q.empty())
	{
	    pair<int,int> p=q.top();
	    q.pop();
	    if(!vis[p.second])
	    {
	        vis[p.second]=true;
	        dis[p.second]=p.first;
	        if(p.second==v-1) break;
	        for(int i=0;i<v;i++)
	        {
	            if(!vis[i] && edge[p.second][i]!=-1)
	            {
	                q.push(make_pair(p.first+edge[p.second][i], i));
	            }
	        }
	    }
	}
	cout<<dis[v-1];
	return 0;
}
