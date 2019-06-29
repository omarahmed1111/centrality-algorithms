#include <bits/stdc++.h>

using namespace std;

const int OO = 1e8;
#define clr(v, d)           memset(v, d, sizeof(v))
#define sz(v)               ((int)((v).size()))
#define rep(i, v)       for(int i=0;i<sz(v);++i)



struct edge {
    int from, to, w;
    edge(int from, int to, int w): from(from), to(to), w(w) {}
    bool operator < (const edge & e) const {
        return w > e.w;
    }
};

vector<vector<int> > dist;
void Dijkstra(vector< vector<edge> >adjList,int n, int src)
{
    dist[src][src] = 0;

    priority_queue<edge> q;
    q.push( edge(-src, src, 0) );

    while( !q.empty() ) {
        edge e = q.top();	q.pop();

        if(e.w > dist[src][e.to])
            continue;

        rep(j, adjList[e.to]) {
            edge ne = adjList[e.to][j];
            if( dist[src][ne.from] > dist[src][ne.to] + ne.w ) {
                ne.w = dist[src][ne.from] = dist[src][ne.to] + ne.w;
                q.push( ne );
                edge nee (adjList[e.to][j].to,adjList[e.to][j].from,adjList[e.to][j].w);
                q.push( nee );
            }
            if( dist[src][ne.to] > dist[src][ne.from] + ne.w ) {
                ne.w = dist[src][ne.to] = dist[src][ne.from] + ne.w;
                q.push( ne );
                edge nee (adjList[e.to][j].to,adjList[e.to][j].from,adjList[e.to][j].w);
                q.push( nee );
            }
        }
    }
}

int main (void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int node1, node2, weight;

    int n,m;

    cin>>n>>m;

    vector< vector<edge> >adjList(n);
    dist=vector<vector<int> > (n, vector<int> (n,OO));

    for (int i=0; i<m; i++)
    {
        cin>>node1>>node2>>weight;
        edge e (node1,node2,weight);
        adjList[node1].push_back(e);
        adjList[node2].push_back(e);
    }
    for(int i=0;i<n;i++) {
        Dijkstra(adjList, n, i);
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += dist[i][j];
        }
        float s = (float) (n - 1) / (float) (sum);
        cout << s << endl;
    }
    return 0;
}
