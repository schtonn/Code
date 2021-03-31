#include "bits/stdc++.h"
using namespace std;
const int N=300010;
int n,m,tot,fa[N],h[N],siz[N],g[N],ans[N];
struct node{
    int v,nxt;
}e[N];
void adde(int u,int v){
    e[++tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
inline void dfs(int u){
    siz[u]=1;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        dfs(v);
        siz[u]+=siz[v];
        g[u]=max(g[u],siz[v]);//重儿子
    }
    int rp=u,rt=g[u];//重心，最大连通块
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        int p=ans[v],t=max(g[p],siz[u]-siz[p]),lt=t,lp=p;
        while(fa[p]!=u){//向上走
            p=fa[p];
            t=max(g[p],siz[u]-siz[p]);
            if(t<lt){lt=t;lp=p;}
            else break;
        }
        if(rt>lt){rt=lt;rp=lp;}
    }
    ans[u]=rp;
}
int main(){
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        adde(fa[i],i);
    }
    dfs(1);
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        cout<<ans[x]<<endl;
    }
    return 0;
}