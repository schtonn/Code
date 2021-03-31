//https://www.luogu.com.cn/record/45620331
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200010,mod=998244353;
int n,f[N][4],c01[N],c23[N],c023[N];
vector<int>G[N];
void dfs(int u,int ff){
    if(G[u].size()==1&&u!=1){f[u][1]=f[u][3]=1;return;}
    for(int v:G[u])if(v!=ff)dfs(v,u);
    int m=0,pa=0;
    for(int v:G[u]){
        if(v==ff)pa=m;
        else{
            c01[++m]=(f[v][0]+f[v][1])%mod;
            c23[m]=(f[v][2]+f[v][3])%mod;
            c023[m]=(0ll+f[v][0]+f[v][2]+f[v][3])%mod;
        }
    }
    c01[0]=c023[m+1]=1;
    for(int i=1;i<=m;i++)c01[i]=1ll*c01[i]*c01[i-1]%mod;
    for(int i=m;i;i--)c023[i]=1ll*c023[i]*c023[i+1]%mod;
    for(int i=1;i<=m;i++)f[u][(i>pa)*2]=(f[u][(i>pa)*2]+1ll*c23[i]*c01[i-1]%mod*c023[i+1]%mod)%mod;
    f[u][1]=1ll*c01[pa]*c023[pa+1]%mod;f[u][3]=c01[m];
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    printf("%d\n",((f[1][0]+f[1][2])%mod+f[1][3])%mod);
    return 0;
}