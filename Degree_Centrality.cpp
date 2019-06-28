#include <bits/stdc++.h>

#define SIZE 1000005

using namespace std;

int main()
{
    int arr[SIZE]={0},n,e,in1,in2;
    scanf("%d %d",&n,&e);
    for(int i=0; i<e; i++){
        scanf("%d %d",&in1,&in2);
        arr[in1] += 1;
        arr[in2] += 1;
    }
    for(int j=0; j<n; j++)
        cout<<j<<" "<<arr[j]<<endl;
}
