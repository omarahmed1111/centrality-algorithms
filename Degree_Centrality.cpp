#include <bits/stdc++.h>

using namespace std;

int main()
{
    int adj[10][10];
    int n,e,in1,in2,d=0;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        cin>>in1>>in2;
        adj[in1][in2] = 1;
        adj[in2][in1] = 1;
    }
    for(int j=0; j<n; j++){
        for(int z=0; z<n; z++){
            if(adj[j][z]==1) d++;
        }
        cout<<"degree of node "<<j+1<<" = "<<d<<endl;
        d=0;
    }
}
