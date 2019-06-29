#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,e,in1,in2;
    scanf("%d %d",&n,&e);
    vector<int> arr(n);
    for(int i=0; i<e; i++){
        scanf("%d %d",&in1,&in2);
        arr[in1] += 1;
        arr[in2] += 1;
    }
    for(int j=0; j<n; j++)
        cout<<j<<" "<<arr[j]<<endl;
}