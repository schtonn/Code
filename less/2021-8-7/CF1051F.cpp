#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll N=100010;
struct node{
    ll v,c,next;
}e[N<<1];
ll tot,h[N];
void add(ll u,ll v,ll c){
    e[++tot].v=v;
    e[tot].c=c;
    e[tot].next=h[u];
    h[u]=tot;
}
struct qnode{
    ll key,c;
    bool operator<(qnode u)const{
        return c>u.c;
    }
};
ll g,vis[N],f[N][23],t[N],d[N],q[N],dis[50][N];
void dfs(ll u,ll fa){
    vis[u]=1,f[u][0]=fa;
    for(ll i=h[u];i;i=e[i].next){
        ll v=e[i].v;
        if(v==fa)continue;
        if(vis[v])q[++g]=u,q[++g]=v;
        else{
            d[v]=d[u]+1,t[v]=t[u]+e[i].c;
            dfs(v,u);
        }
    }
}
ll lca(ll u,ll v){
    if(d[u]<d[v])swap(u,v);
    for(ll i=20;i>=0;--i){
        if(d[f[u][i]]>=d[v])u=f[u][i];
    }
    if(u==v)return u;
    for(ll i=20;i>=0;--i){
        if(f[u][i]!=f[v][i]){
            u=f[u][i],v=f[v][i];
        }
    }
    return f[u][0];
}
inline void dij(ll u){
    memset(dis[u],63,sizeof(dis[u]));
    memset(vis,0,sizeof(vis));
    priority_queue<qnode>qu;
    dis[u][q[u]]=0;
    qu.push((qnode){q[u],0});
    while(!qu.empty()){
        ll tmp=qu.top().key;qu.pop();
        if(vis[tmp])continue;
        vis[tmp]=1;
        for(ll i=h[tmp];i;i=e[i].next){
            ll v=e[i].v;
            if(!vis[v]&&dis[u][tmp]+e[i].c<dis[u][v]){
                dis[u][v]=dis[u][tmp]+e[i].c;
                qu.push((qnode){v,dis[u][v]});
            }
        }
    }
}
ll n,m,p;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(ll i=1;i<=m;++i){
        ll u,v,c;
        cin>>u>>v>>c;
        add(u,v,c),add(v,u,c);
    }
    d[1]=1,dfs(1,0);
    for(ll j=1;j<=20;++j){
        for(ll i=1;i<=n;++i){
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }
    sort(q+1,q+g+1);
    g=unique(q+1,q+g+1)-q-1;
    for(ll i=1;i<=g;++i)dij(i);
    cin>>p;
    while(p--){
        ll u,v;
        cin>>u>>v;
        ll ans=t[u]+t[v]-2*t[lca(u,v)];
        for(ll i=1;i<=g;++i)ans=min(ans,dis[i][u]+dis[i][v]);
        cout<<ans<<endl;
    }
}