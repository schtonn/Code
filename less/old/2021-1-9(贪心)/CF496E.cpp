#include "bits/stdc++.h"
using namespace std;
const int N=10010;
int n,x[N],y[N];
struct node{
    int x,y;
}a[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    if(n<=1)    
    return 0;
}