//https://www.luogu.com.cn/record/45375529
#include "bits/stdc++.h"
using namespace std;
const int N=100010;
struct node{
    int v,nxt;
}e[N<<1];
int n,tot,f[N][3],h[N],w[N],u,k,v;
void adde(int u,int v){
    e[++tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
void dfs(int u,int fa){
    f[u][1]=w[u];
    int flag=0,d=0x3f3f3f3f;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa)continue;
        dfs(v,u);
        if(f[v][1]<=f[v][0])flag=1;
        else d=min(d,f[v][1]-f[v][0]);
        f[u][0]+=min(f[v][0],f[v][1]);
        f[u][1]+=min(min(f[v][0],f[v][1]),f[v][2]);
        f[u][2]+=min(f[v][0],f[v][1]);
    }
    if(!flag)f[u][0]+=d;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;
        cin>>u;
        cin>>w[u]>>m;
        for(int j=1;j<=m;j++){
            cin>>v;
            adde(u,v);
            adde(v,u);
        }
    }
    dfs(1,-1);
    cout<<min(f[1][0],f[1][1]);
    return 0;
}