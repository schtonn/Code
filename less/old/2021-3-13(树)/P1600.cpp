#include "bits/stdc++.h"
#define N 1000010
#define M 1000010
using namespace std;
int tot,n,m;
int w[N],out[M],buc[N+M],ans[N],h[N];
vector<int>v1[M],v2[M],v3[M];
struct node{
    int u,v,dist,lca;
}dat[N];
struct edge{
    int v,nxt;
}e[N];
inline void adde(int u,int v){
    e[++tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
int dep[N],fa[N][25],d[N];
bool use[N];
void dfs(int u,int f){
    use[u]=true;
    dep[u]=f;
    for(int k=1;k<=22;k++){
        int j=fa[u][k-1];
        fa[u][k]=fa[j][k-1];
    }
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(!use[v]){
           fa[v][0]=u;
           d[v]=d[u]+1;
           dfs(v,f+1);
        }
    }
    use[u]=false;
}
inline int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    int step=dep[u]-dep[v];
    for(int k=0;k<=22;k++){
        if((step&(1<<k)))u=fa[u][k];
    }
    for(int k=22;k>=0;k--){
        if(fa[u][k]!=fa[v][k])u=fa[u][k],v=fa[v][k];
    }
    return u==v?u:fa[u][0];
}
void init(){
    fa[1][0]=1;
    dfs(1,0);
}
inline void up(int u){
    use[u]=true;
    int prev=buc[dep[u]+w[u]+N];
    for(int i=h[u];i;i=e[i].nxt){
        if(!use[e[i].v])up(e[i].v);
    }
    buc[dep[u]+N]+=out[u];
    ans[u]+=buc[dep[u]+w[u]+N]-prev;
    int len=v1[u].size();
    for(int k=0;k<len;k++){
        --buc[dep[v1[u][k]]+N];
    }
    use[u]=false;
}
inline void down(int u){
    use[u]=true;
    int prev=buc[w[u]-dep[u]+N];
    for(int i=h[u];i;i=e[i].nxt){
        if(!use[e[i].v])down(e[i].v);
    }
    int len=v2[u].size();
    for(int k=0;k<len;k++){
        ++buc[v2[u][k]+N];
    }
    ans[u]+=buc[w[u]-dep[u]+N]-prev;
    len=v3[u].size();
    for(int k=0;k<len;k++){
        --buc[v3[u][k]+N];
    }
    use[u]=false;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adde(u,v);
        adde(v,u);
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    init();
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        node &g=dat[i];
        g.u=u;g.v=v;g.lca=lca(u,v);
        g.dist=d[u]+d[v]-d[g.lca]*2;
        out[u]++;
        v1[g.lca].push_back(u);
        v2[v].push_back(g.dist-dep[g.v]);
        v3[g.lca].push_back(g.dist-dep[g.v]);
    }
    up(1);
    down(1);
    for(int i=1;i<=m;i++){
        node &g=dat[i];
       if(dep[g.u]==dep[g.lca]+w[g.lca]){
           ans[g.lca]--;
       }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}