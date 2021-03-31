#include "bits/stdc++.h"
using namespace std;
const int N=1000010;
int n,m,dep[N],nxt[N],f[N][40];
bool keep[N];
vector<int> e[N];
void dfs(int x,int f){
    nxt[x]=f;
    int p=e[x].size();
    for(int i=0;i<p;i++){
        if(e[x][i]!=f){
            dep[e[x][i]]=dep[x]+1;
            dfs(e[x][i],x);
        }
    }
}
void dfs2(int x,int f){
    keep[x]=true;
    if(x==f)return;
    dfs2(nxt[x],f);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    m=n-m;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        e[u-1].push_back(v-1);
        e[v-1].push_back(u-1);
    }
    dfs(n-1,-1);
    memset(f,-1,sizeof(f));
    for(int i=0;i<n;i++){
        f[i][0]=nxt[i];
        for(int j=1;(1<<j)<n;j++){
            f[i][j]=-1;
        }
    }
    for(int j=1;(1<<j)<n;j++){
        for(int i=0;i<n;i++){
            if(f[i][j-1]!=-1){
                int a=f[i][j-1];
                f[i][j]=f[a][j-1];
            }
        }
    }
    keep[n-1]=true;
    int sum=1;
    for(int i=n-2;i>=0;i--){
        if(keep[i])continue;
        int t=i;
        for(int j=20;j>=0;j--){
            if(f[t][j]==-1)continue;
            if(!keep[f[t][j]]){
                t=f[t][j];
            }
        }
        if(dep[i]-dep[t]+sum+1<=m){
            sum+=dep[i]-dep[t]+1;
            dfs2(i,t);
        }
    }
    for(int i=0;i<n;i++){
        if(!keep[i]){
            cout<<i+1<<' ';
        }
    }
    return 0;
}