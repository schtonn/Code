#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 500010
struct node{
	int v,nxt,c;
}e[M<<1];
int h[N],tot,dis[N];
bool vis[N];
void adde(int u,int v,int c){
	tot++;
	e[tot].v=v;
	e[tot].c=c;
	e[tot].nxt=h[u];
	h[u]=tot;
}
struct qnode{
	int id,dis;
	bool operator < (const qnode t)const{
		return dis>t.dis;
	}
};
priority_queue<qnode>q;
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	qnode p;
	p.id=s;
	p.dis=0;
	dis[s]=0;
	q.push(p);
	while(!q.empty()){
		p=q.top();
		q.pop();
		int u=p.id;
		if(vis[u])continue;
		vis[u]=true;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].v,c=e[i].c;
			if(!vis[v]&&dis[v]>dis[u]+c){
				dis[v]=dis[u]+c;
				qnode cur;
				cur.id=v;
				cur.dis=dis[v];
				q.push(cur);
			}
		}
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		adde(u,v,c);
	}
	dijkstra(1);
	cout<<dis[n]<<endl;
	return 0;
}