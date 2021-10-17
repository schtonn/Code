#include "bits/stdc++.h"
using namespace std;
const long long p=1e9+7,N=100010;
long long n,m,ans[N];
struct node{
    int v,c,nxt;
}e[N<<2];
int tot,h[N],d[N],siz[N],mx,mxd;
void adde(int u,int v,int c){
    tot++;
    e[tot].v=v;
    e[tot].c=c;
    e[tot].nxt=h[u];
    h[u]=tot;
}
void dfs(int u,int f){
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==f)continue;
        d[v]=d[u]+e[i].c;
        if(d[v]>mx)mxd=v,mx=d[v];
        dfs(v,u);
    }
}
void dfs2(int u,int f){
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==f)continue;
        dfs2(v,u);
        siz[u]+=siz[v];
    }
}
int main(){ 
    cin>>n;
    ans[0]=1;
    for(long long i=1;i<=n;i++){
        ans[i]=(i-1)*(ans[i-1]+ans[i-2])%p;
    }
    for(int i=1;i<n;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adde(u,v,c);
        adde(v,u,c);
    }
    dfs(1,1);
    cout<<mxd<<' '<<mx<<endl;
    dfs(mxd,mxd);
    cout<<mxd<<' '<<mx<<endl;
    return 0;
}