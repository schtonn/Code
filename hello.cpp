#include "bits/stdc++.h"
using namespace std;
const int N=5001,inf=0x3f3f3f3f;
int n,m,s,t,tot=1;
int mn,mx,h[N],dep[N],E[N][N];
bool vis[N];
struct e{
    int nxt,v,c;
}e[N];
inline void adde(int u,int v,int c){
    e[++tot].nxt=h[u];
    e[tot].v=v;
    e[tot].c=c;
    h[u]=tot;
}
int bfs(){
    memset(dep,0,sizeof(dep)); 
    queue<int>q;
    while(!q.empty())q.pop();
    dep[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=h[u];i!=-1;i=e[i].nxt){
            if(e[i].c>0&&dep[e[i].v]==0){
                dep[e[i].v]=dep[u]+1;
                q.push(e[i].v);
            }
        }
    }
    return dep[t];
}
int dfs(int u,int f){
    if(u==t)return f;
    for(int i=h[u];i!=-1;i=e[i].nxt){
        int v=e[i].v,c=e[i].c;
        if((dep[v]==dep[u]+1)&&(c!=0)){
            int nf=dfs(v,min(f,c));
            if(nf>0){
                e[i].c-=nf;
                e[i^1].c+=nf;
                return nf;
            }
        }
    }
    return 0;
}
int dinic(){
    int ans=0;
    while(bfs()){
        while(int nf=dfs(s,inf))ans+=nf;
    }
    return ans;
}
map<int,string>is;
map<string,int>si;
int cnt;
int gets(string s){
    if(si.find(s)!=si.end())return si[s];
    cnt++;
    is[cnt]=s;
    si[s]=cnt;
    return cnt;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string su,sv;
        cin>>su>>sv;
        int u=gets(su),v=gets(sv);
        adde(u,v,inf);
        adde(v,u,0);
        E[u][v]=E[v][u]=1;
    }
    cin>>m;
    t=cnt+2;
    for(int i=1;i<=m;i++){
        string su;
        cin>>su;
        int u=gets(su);
        adde(u,t,1);
        adde(t,u,0);
    }
    string ss;
    cin>>ss;
    s=gets(ss);
    for(int i=1;i<=cnt;i++){
        E[i][i]=1;
        for(int j=1;j<=cnt;j++){
            if(!E[i][j]){
                adde(i,j,inf);
                adde(j,i,inf);
                E[i][j]=E[j][i]=1;
            }
        }
    }
    dinic();
    return 0;
}
/*
2
USA EUROP
EUROPE UK
2
UK
EUROPE
USA
*/