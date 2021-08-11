#include "bits/stdc++.h"
using namespace std;
struct node{
    long long dis;
    int u,v,id;
}t[400010];
struct EDGE{
    long long dis;
    int ver,nxt;
}p[400010];
int depth[200010],f[200020][21],vis[200010],fa[200010],tot,head[200010],n,m,x,y,q,start,end;
long long w[200020][21],cnt;
int find(int x){
    if(fa[x]!=x)fa[x]=find(fa[x]);
    return fa[x];
}
void add(int u,int v,long long l){
    p[++tot].dis=l;
    p[tot].nxt=head[u];
    p[tot].ver=v;
    head[u]=tot;
}
int cmp(node a,node b){
    return a.dis<b.dis;
}
int cmp2(node a,node b){
    return a.id<b.id;
}
void kru(){
    sort(t+1,t+m+1,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int x=t[i].u,y=t[i].v,fx=find(x),fy=find(y);
        if(fx!=fy){
            fa[fx]=fy;
            add(fx,fy,t[i].dis);
            add(fy,fx,t[i].dis);
            cnt+=t[i].dis;
        }
    }
}
void dfs(int u){
    vis[u]=1;
    for(int j=1;j<=20;j++){
        f[u][j]=f[f[u][j-1]][j-1];
        w[u][j]=max(w[u][j-1],w[f[u][j-1]][j-1]);
    }
    for(int i=head[u];i;i=p[i].nxt){
        int v=p[i].ver;
        if(vis[v])continue;
        depth[v]=depth[u]+1;
        f[v][0]=u;
        w[v][0]=p[i].dis;
        dfs(v);
    }
}
long long lca(int x,int y){
    long long ans=0;
    if (depth[x]<depth[y])swap(x,y);
    for(int i=20;i>=0;i--){
        if(depth[f[x][i]]>=depth[y]){
            ans=max(ans,w[x][i]);
            x=f[x][i];
        }
    }
    if (x==y)return ans;
    for(int i=20;i>=0;i--){
    if(f[x][i]!=f[y][i]){
            ans=max(ans,max(w[x][i],w[y][i]));
            x=f[x][i];
                y=f[y][i];
        }
    }
    return max(ans,max(w[x][0],w[y][0]));
} 
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>t[i].u>>t[i].v>>t[i].dis;
            t[i].id=i;
    }
    kru();
    dfs(1);
    long long ans;
    sort(t+1,t+m+1,cmp2);
    for (int i=1;i<=m;i++){
        ans=cnt+t[i].dis-lca(t[i].u,t[i].v);
        cout<<ans<<endl;
    }
    return 0;
}