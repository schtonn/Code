#include<bits/stdc++.h>
#define N 1000005
using namespace std;
typedef long long ll;

inline ll read(){
	ll x=0;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar());
	for(;ch<='9'&&ch>='0';ch=getchar())x=(x<<3)+(x<<1)+(ch^'0');
	return x;
}

const ll mod=998244353;
int n,m,Q,F[N];
int head[N],pre[N<<1],to[N<<1],sz,inde[N];
ll a[N];

inline void addedge(int u,int v){
	pre[++sz]=head[u];head[u]=sz;to[sz]=v;inde[v]++;
}

struct oper{
	int tp,p;
	ll v,mul,sum;
}b[N];

queue<int>q;
int ord[N],bnbn;
void toposort(){//拓扑排序
	for(int i=1;i<=m;i++)if(!inde[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		ord[++bnbn]=x;
		for(int i=head[x];i;i=pre[i]){
			int y=to[i];
			inde[y]--;
			if(!inde[y])q.push(y);
		}
	}
}

void getmul(){//计算节点的mul
	for(int i=m;i;i--){
		int x=ord[i];
		for(int j=head[x];j;j=pre[j]){
			int y=to[j];
			b[x].mul=b[x].mul*b[y].mul%mod;
		}
	}
}

void getsum(){//下传节点的sum
	for(int i=1;i<=m;i++){
		int x=ord[i];ll now=1;
		for(int j=head[x];j;j=pre[j]){
			int y=to[j];
			b[y].sum=(b[y].sum+b[x].sum*now%mod)%mod;
			now=now*b[y].mul%mod;
		}
	}
}

int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read();
	for(int i=1;i<=m;i++){
		b[i].tp=read();
		if(b[i].tp==1){
			b[i].p=read();
            b[i].v=read();
			b[i].mul=1;
		}else if(b[i].tp==2){
			b[i].v=read();
            b[i].mul=b[i].v;
		}else{
			b[i].p=read();
            b[i].mul=1;
			for(int j=1,x;j<=b[i].p;j++){
				x=read();
				addedge(i,x);
			}
		}
	}
	toposort();
	getmul();
	Q=read();
    ll now=1;
	for(int i=1;i<=Q;i++)F[i]=read();
	for(int i=Q;i;i--){
		int x=F[i];b[x].sum=(b[x].sum+now)%mod;
		now=now*b[x].mul%mod;
	}
	getsum();
	for(int i=1;i<=n;i++)a[i]=a[i]*now%mod;
	for(int i=1;i<=m;i++){
		if(b[i].tp==1){
			a[b[i].p]=(a[b[i].p]+b[i].v*b[i].sum%mod)%mod;
		}
	}
	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	return 0;
}