#include "bits/stdc++.h"
using namespace std;
const int INF=0x3f3f3f3f;
const long long INF64=0x3f3f3f3f3f3f3f3fLL;

struct node{
    int u,v,val;
    bool operator<(const node&other)const{return val<other.val;}
};

node e[300010];
bool used[300010];

int n,m;
long long sum;

class Tr{
private:
    struct node{
        int to,nxt,val;
    } e[600010];
    int cnt,head[100010];

    int f[100010][22];
    int dep[100010];
    int mx[100010][22];
    int mn[100010][22];

public:
    void addedge(int u,int v,int val){
        e[++cnt]=(node){v,head[u],val};
        head[u]=cnt;
    }

    void insedge(int u,int v,int val){
        addedge(u,v,val);
        addedge(v,u,val);
    }

    void dfs(int now,int fa){
        dep[now]=dep[fa]+1;
        f[now][0]=fa;
        mn[now][0]=-INF;
        for(int i=1;(1<<i)<=dep[now];i++){
            f[now][i]=f[f[now][i-1]][i-1];
            int g[4]={mx[now][i-1],mx[f[now][i-1]][i-1],mn[now][i-1],mn[f[now][i-1]][i-1]};
            sort(g,g+4);
            mx[now][i]=g[3];
            int ptr=2;
            while(ptr>=0&&g[ptr]==g[3])ptr--;
            mn[now][i]=(ptr==-1?-INF:g[ptr]);
        }
        for(int i=head[now];i;i=e[i].nxt){
            if(e[i].to!=fa){
                mx[e[i].to][0]=e[i].val;
                dfs(e[i].to,now);
            }
        }
    }

    int lca(int a,int b){
        if(dep[a]<dep[b])swap(a,b);
        for(int i=21;i>=0;i--){
            if(dep[f[a][i]]>=dep[b])a=f[a][i];
        }
        if(a==b)return a;
        for(int i=21;i>=0;i--){
            if(f[a][i]!=f[b][i]){
                a=f[a][i];
                b=f[b][i];
            }
        }
        return f[a][0];
    }

    int query(int a,int b,int val){
        int res=-INF;
        for(int i=21;i>=0;i--){
            if(dep[f[a][i]]>=dep[b]){
                if(val!=mx[a][i])res=max(res,mx[a][i]);
                else res=max(res,mn[a][i]);
                a=f[a][i];
            }
        }
        return res;
    }
}tr;

int fa[100010];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

void Kruskal(){
    int tot=0;
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++)fa[i]=i;

    for(int i=1;i<=m;i++){
        int a=find(e[i].u);
        int b=find(e[i].v);
        if(a!=b){
            fa[a]=b;
            tot++;
            tr.insedge(e[i].u,e[i].v,e[i].val);
            sum+=e[i].val;
            used[i]=1;
        }
        if(tot==n-1)break;
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,val;
        cin>>u>>v>>val;
        e[i]=(node){u,v,val};
    }

    Kruskal();
    long long ans=INF64;
    tr.dfs(1,0);

    for(int i=1;i<=m;i++){
        if(!used[i]){
            int _lca=tr.lca(e[i].u,e[i].v);
            long long tmpa=tr.query(e[i].u,_lca,e[i].val);
            long long tmpb=tr.query(e[i].v,_lca,e[i].val);
            ans=min(ans,sum-max(tmpa,tmpb)+e[i].val);
        }
    }
    cout<<ans<<'\n';
    return 0;
}