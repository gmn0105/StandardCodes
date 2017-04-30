#include <bits/stdc++.h>
#include <vector>
using namespace std;
int visited[100001];
vector<int> adj[100001];
void initialize(int n)
{
	for(int i=1;i<=n;i++)
		visited[i] = 0;
}
void dfs(int s)
{
	visited[s] = 1;
	for(int i=0;i<adj[s].size();i++)
	{
		if(!visited[adj[s][i]])
		{
			dfs(adj[s][i]);
		}
	}
}
int main()
{
	int n, m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int x;
	cin>>x;
	initialize(n);
	dfs(x);
	int count = 0;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			count++;
		}
	}
	cout<<count<<endl;
}