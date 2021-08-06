#include "bits/stdc++.h"
using namespace std;
const int N=200010;
int f[N],v[N],l,r,k;
int getf(int x){
    if(f[x]==x)return x;
    int p=getf(f[x]);
    v[x]+=v[f[x]];
    return f[x]=p;
}
bool merge(int a,int b){
    if(a==b)return (v[r]-v[l]!=k);
    f[b]=a;
    v[b]=v[l]+k-v[r];
    return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)f[i]=i;
    int ans=0;
    for(int i=1;i<=m;++i){
        cin>>l>>r>>k;
        l--;
        int a=getf(l),b=getf(r);
        ans+=merge(a,b);
    }
    cout<<ans<<endl;
    return 0;
}