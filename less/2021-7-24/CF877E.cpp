#include "bits/stdc++.h"
using namespace std;
#define ls id<<1
#define rs id<<1|1
const int N=200010;
struct node{
    int l,r,c;
    bool lazy;
}t[N<<2];
int a[N],d[N],rd[N],siz[N];
struct edge{
    int v,nxt;
}e[N<<2];
int h[N],tot,cnt;
void adde(int u,int v){
    tot++;
    e[tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
void dfs(int u){
    d[u]=++cnt;
    rd[d[u]]=u;
    siz[u]=1;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        dfs(v);
        siz[u]+=siz[v];
    }
}
void update(int id){
    t[id].c=t[ls].c+t[rs].c;
}
void rev(int id){
    t[id].c=(t[id].r-t[id].l+1)-t[id].c;
    t[id].lazy^=1;
}
void pushdown(int id){
    if(t[id].lazy){
        rev(ls);
        rev(rs);
        t[id].lazy=0;
    }
}
void build(int id,int l,int r){
    t[id].l=l;
    t[id].r=r;
    if(l==r){
        t[id].c=a[rd[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    update(id);
}
void change(int id,int l,int r){
    if(l<=t[id].l&&t[id].r<=r){
        rev(id);
        return;
    }
    pushdown(id);
    int mid=(t[id].l+t[id].r)>>1;
    if(l<=mid)change(ls,l,r);
    if(r>mid)change(rs,l,r);
    update(id);
}
int query(int id,int l,int r){
    if(l<=t[id].l&&t[id].r<=r){
        return t[id].c;
    }
    pushdown(id);
    int mid=(t[id].l+t[id].r)>>1,ret=0;
    if(l<=mid)ret+=query(ls,l,r);
    if(r>mid)ret+=query(rs,l,r);
    return ret;
}
int n,m;
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u;
        cin>>u;
        adde(u,i+1);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    build(1,1,n);
    cin>>m;
    while(m--){
        string op;
        int x;
        cin>>op>>x;
        if(op=="pow"){
            change(1,d[x],d[x]+siz[x]-1);
        }else{
            cout<<query(1,d[x],d[x]+siz[x]-1)<<endl;
        }
    }
    return 0;
}