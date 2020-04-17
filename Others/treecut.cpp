#include "bits/stdc++.h"
using namespace std;
const int N=2000100;
#define lson id<<1
#define rson id<<1|1
inline int read(){
    int c=1,q=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')c=-1,ch=getchar();
    while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=getchar();
    return c*q;
}
struct node{
    int u,v,nxt;
}e[N];
int head[N];
int tot=1;
struct Tree{
    int l,r,c,siz,f;
}t[N];
int n,m,root,p,dfn=0,rnk[N],a[N];
inline void add(int x,int y){
    e[tot].u=x;
    e[tot].v=y;
    e[tot].nxt=head[x];
    head[x]=tot++;
}
int dep[N],fa[N],son[N],siz[N],top[N],idx[N];
void dfs_1(int u,int f){
    siz[u]=1;
    for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
        if(v==f) continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs_1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])son[u]=v;
    }
}
void update(int id){
    t[id].c=(t[lson].c+t[rson].c+p)%p;
}
void Build(int id,int L,int R){
    t[id].l=L;t[id].r=R;t[id].siz=R-L+1;
    if(L==R){
        t[id].c=rnk[L];
        return;
    }
    int mid=(L+R)>>1;
    Build(lson,L,mid);
    Build(rson,mid+1,R);
    update(id);
}
void dfs_2(int u,int tp){
    idx[u]=++dfn;
    rnk[dfn]=a[u];
    top[u]=tp;
    if(!son[u])return;
    dfs_2(son[u],tp);
    for(int i=head[u];i;i=e[i].nxt){
        if(!idx[e[i].v]){
            dfs_2(e[i].v,e[i].v);
		}
	}
}
void pushdown(int id){
    if(!t[id].f) return ;
    t[lson].c=(t[lson].c+t[lson].siz*t[id].f)%p;
    t[rson].c=(t[rson].c+t[rson].siz*t[id].f)%p;
    t[lson].f=(t[lson].f+t[id].f)%p;
    t[rson].f=(t[rson].f+t[id].f)%p;
    t[id].f=0;
}
void addroute(int id,int L,int R,int c){
    if(L<=t[id].l&&t[id].r<=R){
        t[id].c+=t[id].siz*c;
        t[id].f+=c;
        return;
    }
    pushdown(id);
    int mid=(t[id].l+t[id].r)>>1;
    if(L<=mid)addroute(lson,L,R,c);
    if(R>mid)addroute(rson,L,R,c);
    update(id);
}
void addtree(int x,int y,int c){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        addroute(1,idx[top[x]],idx[x],c);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    addroute(1,idx[x],idx[y],c);
}
int sumroute(int id,int L,int R){
    int ans=0;
    if(L<=t[id].l&&t[id].r<=R)
        return t[id].c;
    pushdown(id);
    int mid=(t[id].l+t[id].r)>>1;
    if(L<=mid) ans=(ans+sumroute(lson,L,R))%p;
    if(R>mid)  ans=(ans+sumroute(rson,L,R))%p;
    return ans;
}
void treesum(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans=(ans+sumroute(1,idx[top[x]],idx[x]))%p;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans=(ans+sumroute(1,idx[x],idx[y]))%p;
    printf("%d\n",ans);
}
int main(){
    n=read();m=read();root=read();p=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n-1;i++){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    dfs_1(root,root);
    dfs_2(root,root);
    Build(1,1,n);
    while(m--){
        int op=read(),x,y,z;
        if(op==1){    
            x=read();y=read();z=read();z=z%p;
            addtree(x,y,z);
        }
        else if(op==2){
            x=read();y=read();
            treesum(x,y);
        }
        else if(op==3){
            x=read(),z=read();
            addroute(1,idx[x],idx[x]+siz[x]-1,z%p);
        }
        else if(op==4){
            x=read();
            printf("%d\n",sumroute(1,idx[x],idx[x]+siz[x]-1));
        }
    }
    return 0;
}
