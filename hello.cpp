#include "bits/stdc++.h"
using namespace std;
const int N=1000010;
struct edge{
    int v,nxt;
}e[N<<2];
int h[N],tot,n,m,a[N];
void adde(int u,int v){
    tot++;
    e[tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
int f[N],d[N],siz[N],son[N];
void dfs1(int u){
    siz[u]=1;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(d[v])continue;
        d[v]=d[u]+1;
        f[v]=u;
        dfs1(v);
        siz[u]+=siz[v];
        if(!son[u]||siz[son[u]]<siz[v])son[u]=v;
    }
}
int top[N],dfn[N],rnk[N],btn[N],dtot;
void dfs2(int u,int ctop){
    top[u]=ctop;
    dfn[u]=++dtot;
    rnk[dtot]=u;
    btn[u]=dfn[u]+siz[u]-1;
    if(!son[u])return;
    dfs2(son[u],ctop);
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==son[u]||v==f[u])continue;
        dfs2(v,v);
    }
}


#define ls id<<1
#define rs id<<1|1
struct node{
    int l,r,sum,lazy;
}t[2*N];
void update(int id){
    t[id].sum=t[ls].sum+t[rs].sum;
}
void pushdown(int id){
    if(t[id].lazy!=-1){
        t[ls].lazy=t[id].lazy;
        t[rs].lazy=t[id].lazy;
        int len=(t[id].r-t[id].l+1);
        t[ls].sum=t[id].lazy*(len-(len>>1));
        t[rs].sum=t[id].lazy*(len>>1);
        t[id].lazy=-1;
    }
}
void buildtree(int id,int l,int r){
    t[id].l=l;
    t[id].r=r;
    t[id].lazy=-1;
    if(l==r){
        t[id].sum=a[rnk[l]];
        return;
    }
    int mid=(l+r)>>1;
    buildtree(ls,l,mid);
    buildtree(rs,mid+1,r);
    update(id);
}
void change(int id,int l,int r,int c){
    if(t[id].l>=l&&t[id].r<=r){
        t[id].lazy=c;
        t[id].sum=c*(t[id].r-t[id].l+1);
        return;
    }
    pushdown(id);
    if(t[ls].r>=r)change(ls,l,r,c);
    else if(t[rs].l<=l)change(rs,l,r,c);
    else{
        change(ls,l,t[ls].r,c);
        change(rs,t[rs].l,r,c);
    }
    update(id);
}
int query(int id,int l,int r){
    if(t[id].l>=l&&t[id].r<=r){
        return t[id].sum;
    }
    pushdown(id);
    if(t[ls].r>=r)return query(ls,l,r);
    else if(t[rs].l<=l)return query(rs,l,r);
    else{
        return query(ls,l,t[ls].r)+query(rs,t[rs].l,r);
    }
}




void linkChange(int u,int v,int c){
    while(top[u]!=top[v]){
        if(d[top[u]]>d[top[v]]){
            change(1,dfn[top[u]],dfn[u],c);
            u=f[top[u]];
        }else{
            change(1,dfn[top[v]],dfn[v],c);
            v=f[top[v]];
        }
    }
    if(dfn[u]>dfn[v])swap(u,v);
    if(dfn[u]==dfn[v])return;
    change(1,dfn[u]+1,dfn[v],c);
}
int linkQuery(int u,int v){
    int ret=0;
    while(top[u]!=top[v]){
        if(d[top[u]]>d[top[v]]){
            ret+=query(1,dfn[top[u]],dfn[u]);
            u=f[top[u]];
        }else{
            ret+=query(1,dfn[top[v]],dfn[v]);
            v=f[top[v]];
        }
    }
    if(dfn[u]>dfn[v])swap(u,v);
    if(dfn[u]==dfn[v])return ret;
    ret+=query(1,dfn[u]+1,dfn[v]);
    return ret;
}
inline int lca(int a,int b){
	while(top[a]!=top[b]){
		if(d[top[a]]>d[top[b]])a=f[top[a]];
		else b=f[top[b]];
	}
	return d[a]<d[b]?a:b;
}

int main(){
    freopen("edge.in","r",stdin);
    freopen("edge.out","w",stdout);
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        tot=0;
        memset(d,0,sizeof(d));
        memset(son,0,sizeof(son));
        for(int i=2;i<=n;i++){
            int u,v;
            cin>>u>>v;
            adde(u,v);
        }
        d[1]=1;
        dfs1(1);
        dfs2(1,1);
        buildtree(1,1,n);
        for(int i=1;i<=m;i++){
            int op,u,v,l;
            cin>>op;
            switch(op){
                case 1:
                    cin>>u>>v;
                    l=lca(u,v);
                    change(1,dfn[l],dfn[l]+siz[l]-1,0);
                    linkChange(u,v,1);
                    break;
                case 2:
                    cin>>u>>v;
                    cout<<linkQuery(u,v)<<endl;
                    break;
            }
        }
    }
    return 0;
}