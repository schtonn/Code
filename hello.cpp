#include "bits/stdc++.h"
using namespace std;
const int N=1010;
int h[N],val[N],ans;
bool vis[N],vis2[N],a[N];
struct node{
    int v,nxt;
}e[N<<2];
int tot;
void add(int u,int v){
    e[++tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
void dfs(int u){
    if(vis[u])return;
    vis[u]=1;
    for(int i=h[u];i;i=e[i].nxt){
        dfs(e[i].v);
    }
}
int dfs2(int u){
    if(vis2[u]||vis[u])return 0;
    vis2[u]=1;
    for(int i=h[u];i;i=e[i].nxt){
        val[u]+=dfs2(e[i].v);
    }
    return val[u]+(!vis[u]&&a[u]);
}
map<string,int>si;
int cnt;
int gets(string s){
    if(si.find(s)!=si.end())return si[s];
    cnt++;
    si[s]=cnt;
    return cnt;
}
bool check(){
    for(int i=1;i<=cnt;i++)if(a[i]&&!vis[i])return true;
    return false;
}
int main(){
    // freopen("adapters.in","r",stdin);
    // freopen("adapters.out","w",stdout);
    int n,m,s;
    cin>>n;
    for(int i=1;i<=n;i++){
        string uu,vv;
        cin>>uu>>vv;
        int u=gets(uu),v=gets(vv);
        add(u,v);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        string tt;
        cin>>tt;
        a[gets(tt)]=1;
    }
    string ss;
    cin>>ss;
    s=gets(ss);
    dfs(s);
    while(check()){
        memset(val,0,sizeof(val));
        memset(vis2,0,sizeof(vis2));
        int mx=0,id=0;
        for(int i=1;i<=cnt;i++){
            dfs2(i);
            if(val[i]>mx){
                mx=val[i];
                id=i;
            }
        }
        add(s,id);
        ans++;
        memset(vis,0,sizeof(vis));
        dfs(s);
    }
    cout<<ans<<endl;
    return 0;
}
/*
6
1 2
2 3
3 4
4 1
1 5
6 7
6
2
3
4
5
6
7
1

*/