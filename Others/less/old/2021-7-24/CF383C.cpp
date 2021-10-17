#include "bits/stdc++.h"
using namespace std;
const int N=200010;
struct node{
    int v,nxt;
}e[N<<2];
int a[N],d[N],rd[N],siz[N],dep[N];
int h[N],tot,cnt;
void adde(int u,int v){
    tot++;
    e[tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
void dfs(int u,int f){
    d[u]=++cnt;
    rd[d[u]]=u;
    siz[u]=1;
    if(!dep[u])a[u]=-a[u];
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==f)continue;
        dep[v]=dep[u]^1;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
int n,m,t[200005];
int lowbit(int x){
    return x&-x;
}
void add(int u,int c){
    while(u<=n){
        t[u]+=c;
        u+=lowbit(u);
    }
}
int sum(int u){
    int ans=0;
    while(u){
        ans+=t[u];
        u-=lowbit(u);
    }
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adde(u,v);
        adde(v,u);
    }
    dep[1]=1;
    dfs(1,1);
    for(int i=1;i<=n;i++){
        add(i,a[rd[i]]-a[rd[i-1]]);
    }
    while(m--){
        int op,u,c;
        cin>>op;
        if(op==1){
            cin>>u>>c;
            if(dep[u])add(d[u],c),add(d[u]+siz[u],-c);
            else add(d[u],-c),add(d[u]+siz[u],c);
        }
        else{
            cin>>u;
            cout<<sum(d[u])*(dep[u]?1:-1)<<endl;
        }
    }
    return 0;
}