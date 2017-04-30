#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long int lli;
vector <lli> f,adj[100000],visited;  //adj[][] is the adjacency list
void dfs(lli p) {
    visited[p] = 1;
    for(lli i = 0;i < adj[p].size();i++)
        if(visited[i])
        dfs(p);
}
