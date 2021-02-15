#include "bits/stdc++.h"
using namespace std;
const int N=10010,inf=0x3f3f3f3f;
struct node{
    int v,c,nxt;
}e[N<<1];
int tot=1,h[N],hp[N];
void adde(int u,int v,int c){
    e[++tot].v=v;
    e[tot].c=c;
    e[tot].nxt=h[u];
    h[u]=tot;
}
int n,m,ans,dep[N];
bool bfs(){
    memset(dep,0,sizeof(dep));
    queue<int>q;
    while(!q.empty())q.pop();
    dep[1]=1;
    q.push(1);
    do{
        int u=q.front();
        q.pop();
        for(int i=h[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(e[i].c&&!dep[v]){
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }while(!q.empty());
    return dep[n];
}
int dfs(int u,int f){
    if(u==n)return f;
    int ret=0;
    for(int &i=hp[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(e[i].c&&dep[v]==dep[u]+1){
            int fv=dfs(v,min(f,e[i].c));
            e[i].c-=fv;
            e[i^1].c+=fv;
            f-=fv;
            ret+=fv;
            if(!f)return ret;
        }
    }
    return ret;
}
void solve(){
    while(bfs()){
        memcpy(hp,h,sizeof(h));
        ans+=dfs(1,inf);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adde(u,v,c);
        adde(v,u,0);
    }
    solve();
    cout<<ans<<endl;
    return 0;
}