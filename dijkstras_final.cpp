#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define SIZE 100000 + 1
const int INF = 1<<29;
vector <pair < int , int > > v [100001];   // each vertex has all the connected vertices with the edges weights
bool vis[100001];
int dist[100001];
void dijkstra(int src){
    //memset(dist, INF, sizeof dist);
    fill(dist, dist+100001, INF);// set the vertices distances as infinity
    //memset(vis, false , sizeof vis);
    fill(vis, vis+100001, false);// set all vertex as unvisited
    dist[src] = 0;
    multiset<pair< int , int > > s;          // multiset do the job as a min-priority queue

    s.insert({0 , src});                          // insert the source node with distance = 0

    while(!s.empty()){

        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.second; int wei = p.first;
        if(vis[x]) continue;                  // check if the popped vertex is visited before
        vis[x] = true;
        /*for(int i=1;i<=3;i++)
            {
            cout<<vis[i]<<" ";
        }
        cout<<endl;*/
        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].first; 
            int w = v[x][i].second;
            if(dist[x] + w < dist[e]){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + w;
                //cout<<dist[e]<<" "<<e<<"\n";
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }
    }
}
void initialise(int n)
{
    for(int i=1;i<=n;i++)
    {
        v[i].clear();
    }
}
int main()
{
    int t;
    scanf("%d", &t);//cin>>t;
    for(int j=0;j<t;j++)
    {
        int n,m;
        scanf("%d %d", &n,&m);//cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int x, y, r;
            scanf("%d %d %d", &x,&y,&r);//cin>>x>>y>>r;
            v[x].push_back(make_pair(y, r));
            v[y].push_back(make_pair(x, r));
        }
        int s;
        scanf("%d", &s);//cin>>s;
        dijkstra(s);
        for(int i=1;i<=n;i++)
        {
            if(i==s)
                continue;
            else if(dist[i]!=INF)
                printf("%d ", dist[i]);//cout<<dist[i]<<" ";
            else
                printf("-1 ");//cout<<"-1 ";
        }
        printf("\n");
        initialise(n);
    }
}