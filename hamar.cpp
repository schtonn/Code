#include "bits/stdc++.h"
using namespace std;
const int N=100010,M=100010;
int n,m,a[N],b[N],bb[N],c[M];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int k=1;k<=n;k++){
        memcpy(bb,b,sizeof(b));
        int p=k-1;
        while(bb[c[p%n+1]]>=a[p%n+1]){
            bb[c[p%n+1]]-=a[p%n+1];
            p++;
        }
        cout<<p-k+1<<' ';
    }
    return 0;
}