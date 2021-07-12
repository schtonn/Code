#include "bits/stdc++.h"
using namespace std;
const int N=5001,inf=0x3f3f3f3f;
int n,m,s,t,tot=1;
int mn,mx;
int cd[N],h[N],fd[N],fa[N];
bool vis[N],E[N][N];
struct e{
    int nxt,v,c,f;
}e[N];
inline void adde(int u,int v,int c,int f){
    e[++tot].nxt=h[u];
    e[tot].v=v;
    e[tot].c=c;
    e[tot].f=f;
    h[u]=tot;
}
inline bool spfa(){
    queue<int>q;
    memset(cd,0x3f,sizeof(cd));
    memset(vis,0,sizeof(vis));
    q.push(s);
    cd[s]=0;
    vis[s]=1;
    fd[s]=inf;
    while(!q.empty()){
        int u=q.front();
        cout<<u<<endl;
        vis[u]=0;
        q.pop();
        for(register int i=h[u];i;i=e[i].nxt){
            if(!e[i].f)continue;
            int v=e[i].v;
            if(cd[v]>cd[u]+e[i].c){
                cd[v]=cd[u]+e[i].c;
                fd[v]=min(fd[u],e[i].f);
                fa[v]=i;
                if(!vis[v])vis[v]=1,q.push(v);
            }
        }
    }
    if(cd[t]==inf)return 0;
    return 1;
}
inline void MCMF(){
    while(spfa()){
        int x=t;
        mx+=fd[t];
        mn+=cd[t];
        int u;
        while(x!=s){
            u=fa[x];
            e[u].f-=fd[t];
            e[u^1].f+=fd[t];
            x=e[u^1].v;
        }
    }
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
        adde(u,v,0,inf);
        adde(v,u,0,0);
        E[u][v]=E[v][u]=1;
    }
    cin>>m;
    t=cnt+2;
    for(int i=1;i<=m;i++){
        string su;
        cin>>su;
        int u=gets(su);
        adde(u,t,0,1);
        adde(t,u,0,0);
    }
    string ss;
    cin>>ss;
    s=gets(ss);
    for(int i=1;i<=cnt;i++){
        E[i][i]=1;
        for(int j=1;j<=cnt;j++){
            if(!E[i][j]){
                adde(i,j,1,inf);
                adde(j,i,1,inf);
                E[i][j]=E[j][i]=1;
            }
        }
    }
    MCMF();
    cout<<mn<<' '<<mx<<endl;
    return 0;
}
/*
1
6 7
2
6
7
1

2
1 2
3 4
2
3
4
1
*/