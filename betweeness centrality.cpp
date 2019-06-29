//============================================================================
// Name        : p1.cpp
// Author      : omar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
typedef long long ll;
const ll OO = 2e9;

const double EPS = (1e-9);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
const double PI  = acos(-1.0);
#define pb					push_back
#define MP					make_pair
typedef long double   	  ld;
typedef unsigned long long int   	  ull;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef vector<bool>      vb;
typedef vector<long long int>      vll;

int n,m;
vector< vector< pair<int,int> > > g;
vector< vector<int> > diks(int s,int c){
	priority_queue< pair<int,int>, vector< pair< int, int> >,greater< pair<int,int> > > p;
	vector<int> cost(n+1,1e8);
	vector< vector<int> > parent(n+1);
	cost[s] = 0;
	p.push(MP(c,s));
	while(!p.empty()){
		pair<int,int> t = p.top();
		p.pop();
		ll cr = t.first;
		for(int i = 0 ; i<sz(g[t.second]);i++){
			if(cr+g[t.second][i].second<cost[g[t.second][i].first]){
				cost[g[t.second][i].first] = cr+g[t.second][i].second;
				parent[g[t.second][i].first].clear();
				parent[g[t.second][i].first].pb(t.second);
				p.push(MP(cr+g[t.second][i].second,g[t.second][i].first));

			}
			else if(cr+g[t.second][i].second==cost[g[t.second][i].first]){
				parent[g[t.second][i].first].pb(t.second);
			}

		}


	}
	return parent;

}
int tot=0;
int between(int begin,int from,int x,vector< vector<int> >&p){
	if(begin==from){
		tot++;
		return 0;
	}

	int k = 0;

	lp(i,sz(p[from])){

		k+=between(begin,p[from][i],x,p);
		if(from==x)k++;
	}
	return k;

}

int main() {

	cin>>n>>m;
	g.resize(n+1);
	lp(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].pb(MP(b,c));
		g[b].pb(MP(a,c));
	}
	lp(i,n){
		double ans = 0;
		lp(x,n){
			if(x==i)continue;
			vector< vector<int> > parent = diks(x,0);
			lpi(j,x+1,n){
				if(j==i)continue;
				tot=0;
				int k = between(x,j,i,parent);
				ans+= (double)k/tot;
			}
		}
		cout<<fixed<<setprecision(10)<<ans<<'\n';
	}



}

