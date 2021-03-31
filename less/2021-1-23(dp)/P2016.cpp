//https://www.luogu.com.cn/record/45372044
#include "bits/stdc++.h"
using namespace std;
const int N=1510;
struct node{
    int v,nxt;
}e[N<<1];
int n,tot,f[N][2],h[N],u,k,v;
void adde(int u,int v){
    e[++tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
void dfs(int u){
    f[u][1]=1;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        dfs(v);
        f[u][0]+=f[v][1];
        f[u][1]+=min(f[v][0],f[v][1]);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>u>>k;
        for(int j=1;j<=k;j++){
            cin>>v;
            adde(u,v);
        }
    }
    dfs(0);
    cout<<min(f[0][0],f[0][1]);
    return 0;
}