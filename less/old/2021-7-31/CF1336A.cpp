#include "bits/stdc++.h"
using namespace std;
const int N=200010;
struct node{
    int v,nxt;
}e[N<<2];
int h[N],tot,siz[N],d[N],a[N];
int n,k;
long long ans;
void adde(int u,int v){
    tot++;
    e[tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
void dfs(int u,int f){
    d[u]=d[f]+1;
    siz[u]=1;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==f)continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
    a[u]=d[u]-siz[u];
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n-1;++i){
        int u,v;
        cin>>u>>v;
        adde(u,v);
        adde(v,u);
    }
    dfs(1,0);
    nth_element(a+1,a+k,a+n+1,greater<int>());
    for(int i=1;i<=k;++i)ans+=a[i];
    cout<<ans<<endl;
    return 0;
}