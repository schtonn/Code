#include "bits/stdc++.h"
using namespace std;
const long long N=1000010;

struct edge{
    long long v,nxt;
}e[N<<2];
long long h[N],tot,n,m,rt=1,a[N];
void adde(long long u,long long v){
    tot++;
    e[tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
long long f[N],d[N],siz[N],son[N];
void dfs1(long long u){
    siz[u]=1;
    for(long long i=h[u];i;i=e[i].nxt){
        long long v=e[i].v;
        if(f[u]==v)continue;
        d[v]=d[u]+1;
        dfs1(v);
        siz[u]+=siz[v];
        if(!son[u]||siz[son[u]]<siz[v])son[u]=v;
    }
}
long long top[N],dfn[N],rnk[N],btn[N],dtot;
void dfs2(long long u,long long ctop){
    top[u]=ctop;
    dfn[u]=++dtot;
    rnk[dtot]=u;
    btn[u]=dfn[u]+siz[u]-1;
    if(!son[u])return;
    dfs2(son[u],ctop);
    for(long long i=h[u];i;i=e[i].nxt){
        long long v=e[i].v;
        if(v==son[u]||v==f[u])continue;
        dfs2(v,v);
    }
}


#define ls id<<1
#define rs id<<1|1
struct node{
    long long l,r,sum,lazy;
}t[2*N];
void update(long long id){
    t[id].sum=t[ls].sum+t[rs].sum;
}
void pushdown(long long id){
    if(t[id].lazy){
        t[ls].lazy+=t[id].lazy;
        t[rs].lazy+=t[id].lazy;
        long long len=(t[id].r-t[id].l+1);
        t[ls].sum+=t[id].lazy*(len-(len>>1));
        t[rs].sum+=t[id].lazy*(len>>1);
        t[id].lazy=0;
    }
}
void buildtree(long long id,long long l,long long r){
    t[id].l=l;
    t[id].r=r;
    t[id].lazy=0;
    if(l==r){
        t[id].sum=a[rnk[l]];
        return;
    }
    long long mid=(l+r)>>1;
    buildtree(ls,l,mid);
    buildtree(rs,mid+1,r);
    update(id);
}
void change(long long id,long long l,long long r,long long c){
    if(t[id].l>=l&&t[id].r<=r){
        t[id].lazy+=c;
        t[id].sum+=c*(t[id].r-t[id].l+1);
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
long long query(long long id,long long l,long long r){
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




void linkChange(long long u,long long v,long long c){
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
    change(1,dfn[u],dfn[v],c);
}
long long linkQuery(long long u,long long v){
    long long ret=0;
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
    ret+=query(1,dfn[u],dfn[v]);
    return ret;
}
long long getson(long long u){
    long long v=rt;
    while(top[u]!=top[v]){
        if(f[top[v]]==u)return top[v];
        if(d[v]<d[u])return 0;
        v=f[top[v]];
    }
    if(d[v]<d[u])return 0;
    return son[u];
}
void treeChange(long long u,long long c){
    if(u==rt){
        change(1,1,n,c);
    }else{
        long long v=getson(u);
        if(v){
            change(1,1,n,c);
            change(1,dfn[v],btn[v],-c);
        }else{
            change(1,dfn[u],btn[u],c);
        }
    }
}
long long treeQuery(long long u){
    if(u==rt){
        return query(1,1,n);
    }else{
        long long v=getson(u);
        if(v){
            return query(1,1,n)-query(1,dfn[v],btn[v]);
        }else{
            return query(1,dfn[u],btn[u]);
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=2;i<=n;i++){
        cin>>f[i];
        adde(f[i],i);
    }
    d[1]=1;
    dfs1(1);
    dfs2(1,1);
    buildtree(1,1,n);
    cin>>m;
    for(long long i=1;i<=m;i++){
        long long op,u,v,k;
        cin>>op;
        switch(op){
            case 1:
                cin>>rt;
                break;
            case 2:
                cin>>u>>v>>k;
                linkChange(u,v,k);
                break;
            case 3:
                cin>>u>>k;
                treeChange(u,k);
                break;
            case 4:
                cin>>u>>v;
                cout<<linkQuery(u,v)<<endl;
                break;
            case 5:
                cin>>u;
                cout<<treeQuery(u)<<endl;
                break;
        }
    }
    return 0;
}