//https://www.luogu.com.cn/record/45372483
#include "bits/stdc++.h"
using namespace std;
const int N=100010;
struct node{
    int v,nxt;
}e[N<<1];
int n,tot,f[N][2],h[N],r[N],u,k,v;
void adde(int u,int v){
    e[++tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
void dfs(int u,int fa){
    f[u][1]=r[u];
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa)continue;
        dfs(v,u);
        f[u][0]+=max(f[v][0],f[v][1]);
        f[u][1]+=f[v][0];
    }
}
bool son[N];
int rt;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    for(int i=1;i<n;i++){
        cin>>u>>v;
        son[u]=1;
        adde(u,v);
        adde(v,u);
    }
    for(int i=1;i<=n;i++){
        if(!son[i]){
            rt=i;break;
        }
    }
    dfs(rt,-1);
    cout<<max(f[rt][0],f[rt][1]);
    return 0;
}