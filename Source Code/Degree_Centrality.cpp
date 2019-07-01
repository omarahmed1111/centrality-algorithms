#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,e,in1,in2,w;
    scanf("%d %d",&n,&e);
    vector<int> arr(n,0);

    for(int i=0; i<e; i++){
        scanf("%d %d %d",&in1,&in2,&w);
        arr[in1] += 1;
        arr[in2] += 1;
    }
    for(int j=0; j<n; j++)
        printf("%d\n",arr[j]);
}
