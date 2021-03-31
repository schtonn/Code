#include "bits/stdc++.h"
using namespace std;
#define N 200006
int n;
int a[N],deg[N];
vector<int>e[N],re;

struct node{
    int u,v,w,id;
}g[N];int id;

int dfn[N],tot;

void dfs(int u,int fa){
    dfn[u]=tot+1;
    if(u!=1&&deg[u]==1)++tot;
    for(int v:e[u])if(v!=fa)dfs(v,u);
    g[++id]={dfn[u],tot+1,a[u],u};
}

bool cmp(node u,node v){
    return u.w<v.w;
}

int fa[N];
int getf(int x){
    return x==fa[x]?x:fa[x]=getf(fa[x]);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    dfs(1,1);
    sort(g+1,g+1+n,cmp);
    for(int i=1;i<=tot+1;i++)fa[i]=i;
    long long ans=0;
    for(int i=1,j;i<=n;i=j){
        j=i;
        while(j!=n+1&&g[j].w==g[i].w){
            u=getf(g[j].u);
            v=getf(g[j].v);
            if(u!=v)re.push_back(g[j].id);
            ++j;
        }
        for(int k=i;k<=j-1;k++){
            u=getf(g[k].u);
            v=getf(g[k].v);
            if(u!=v)fa[u]=v,ans+=g[k].w;
        }
    }
    cout<<ans<<' '<<re.size()<<endl;
    sort(re.begin(),re.end());
    for(int i:re)cout<<i<<' ';
    return 0;
}