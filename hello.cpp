#include "bits/stdc++.h"
using namespace std;
const int N=500010;

struct edge{
	int v,nxt;
}e[N<<2];
int h[N],tot,n,m,rt=1,a[N];
void adde(int u,int v){
	tot++;
	e[tot].v=v;
	e[tot].nxt=h[u];
	h[u]=tot;
}
int f[N],d[N],siz[N],s[N];
inline void dfs1(int u){
	siz[u]=1;
	for(int i=h[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(f[u]==v)continue;
		d[v]=d[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(!s[u]||siz[s[u]]<siz[v])s[u]=v;
	}
}
int top[N],dfn[N],rnk[N],btn[N],dtot;
inline void dfs2(int u,int ctop){
	top[u]=ctop;
	dfn[u]=++dtot;
	rnk[dtot]=u;
	btn[u]=dfn[u];
	if(!s[u])return;
	dfs2(s[u],ctop);
	for(int i=h[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==s[u]||v==f[u])continue;
		dfs2(v,v);
		btn[u]=max(btn[u],dfn[v]);
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
    if(t[id].lazy){
        t[ls].lazy+=t[id].lazy;
        t[rs].lazy+=t[id].lazy;
        int len=(t[id].r-t[id].l+1);
        t[ls].sum+=t[id].lazy*(len-(len>>1));
        t[rs].sum+=t[id].lazy*(len>>1);
        t[id].lazy=0;
    }
}
void buildtree(int id,int l,int r){
    t[id].l=l;
    t[id].r=r;
    t[id].lazy=0;
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




inline void lchange(int x,int y,int c){
	while(top[x]!=top[y]){
		if(d[top[x]]>d[top[y]]){
			change(1,dfn[top[x]],dfn[x],c);
			x=f[top[x]];
		}else{
			change(1,dfn[top[y]],dfn[y],c);
			y=f[top[x]];
		}
	}
	if(dfn[x]>dfn[y])swap(x,y);
	change(1,dfn[x],dfn[y],c);
}
inline void lquery(int x,int y){
	int ret=0;
	while(top[x]!=top[y]){
		if(d[top[x]]>d[top[y]]){
			ret+=query(1,dfn[top[x]],dfn[x]);
			x=f[top[x]];
		}else{
			ret+=query(1,dfn[top[y]],dfn[y]);
			y=f[top[x]];
		}
	}
	if(dfn[x]>dfn[y])swap(x,y);
	ret+=query(1,dfn[x],dfn[y]);
}
inline void tchange(int x,int c){
	change(1,dfn[x],dfn[btn[x]],c);
}
inline int tquery(int x){
	return query(1,dfn[x],dfn[btn[x]]);
}
inline int lca(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]>d[top[y]])x=f[top[x]];
		else y=f[top[y]];
	}
	return d[x]<d[y]?x:y;
}



int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		cin>>f[i];
		adde(f[i],i);
	}
	d[1]=1;
	dfs1(1);
	dfs2(1,1);
	cin>>m;
	for(int i=1;i<=m;i++){
		int op,u,v,k;
		cin>>op;
		switch(op){
			case 1:
				cin>>u;
				break;
			case 2:
				cin>>u>>v>>k;
				break;
			case 3:
				cin>>u>>k;
				break;
			case 4:
				cin>>u>>v;
				break;
			case 5:
				cin>>u;
				break;
			default:
				break;
		}
	}
	return 0;
}