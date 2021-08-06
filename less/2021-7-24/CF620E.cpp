#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define ls id<<1
#define rs id<<1|1
const int N=400010;
struct edge{
    int v,nxt;
}e[N<<2];
int h[N],tot,d[N],rd[N],siz[N],cnt;
int a[N];
void adde(int u,int v){
    tot++;
    e[tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
void dfs(int u,int f){
    d[u]=++cnt;
    rd[cnt]=u;
    siz[u]=1;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==f)continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
struct node{
    int l,r;
    ll c,lazy;
}t[N<<2];
void update(int id){
    t[id].c=t[ls].c|t[rs].c;
}
void pushdown(int id){
    if(t[id].lazy){
        t[ls].c=t[rs].c=t[id].lazy;
        t[ls].lazy=t[rs].lazy=t[id].lazy;
        t[id].lazy=0;
    }
}
void build(int id,int l,int r){
    t[id].l=l;
    t[id].r=r;
    t[id].lazy=0;
    if(l==r){
        t[id].c=1LL<<a[rd[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    update(id);
}
void change(int id,int l,int r,int c){
    if(l<=t[id].l&&t[id].r<=r){
        t[id].c=1LL<<c;
        t[id].lazy=1LL<<c;
        return;
    }
    pushdown(id);
    int mid=(t[id].l+t[id].r)>>1;
    if(l<=mid)change(ls,l,r,c);
    if(r>mid)change(rs,l,r,c);
    update(id);
}
ll query(int id,int l,int r){
    if(l<=t[id].l&&t[id].r<=r){
        return t[id].c;
    }
    pushdown(id);
    ll ans=0;
    int mid=(t[id].l+t[id].r)>>1;
    if(l<=mid)ans|=query(ls,l,r);
    if(r>mid)ans|=query(rs,l,r);
    return ans;
}
ll lowbit(ll x){return x&-x;}
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adde(u,v);
        adde(v,u);
    }
    dfs(1,0);
    build(1,1,n);
    while(m--){
        int op,x,y;
        cin>>op;
        if(op==1){
            cin>>x>>y;
            change(1,d[x],d[x]+siz[x]-1,y);
        }else{
            cin>>x;
            ll q=query(1,d[x],d[x]+siz[x]-1),ans=0;
            while(q){
                ans++;
                q-=lowbit(q);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}