#include <vector>
#include <cstdio>
#include <deque>
using namespace std;
typedef long long int lli;
vector <lli> adj[100000];
vector <bool> visited;  //adj[][] is the adjacency list
void bfs(lli p)
{
    deque<lli> Q;
    Q.clear();
    visited[p]=1;
    while (Q.empty()) {
        lli p1 = Q.front();
        Q.pop_front();
        for (int i=0; i<adj[p1].size(); i++) {
            if( !visited[ adj[p1][i] ] )
            {
                Q.push_back( adj[p1][i] );
                visited[adj[p1][i]]=1;
            }
        }
    }
}