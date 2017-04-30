#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
int visited[100001];
vector<int> adj[100001];
int level[100001];
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		for(int i=0;i<adj[p].size();i++)
		{
			if(!visited[adj[p][i]])
			{
				q.push(adj[p][i]);
				visited[adj[p][i]] = 1;
				level[adj[p][i]] = level[p] + 1;
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int x;
	cin>>x;
	bfs(1);
	int count = 0;
	for(int i=1;i<=n;i++)
	{
		if(level[i]+1==x)
		{
			count++;
		}
	}
	for(int i=1;i<=n;i++)
    {
        cout<<level[i]<<" ";
    }
    cout<<endl;
	cout<<count<<endl;
}
