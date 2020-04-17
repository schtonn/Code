#include "bits/stdc++.h"
using namespace std;
 
const int Maxn=10000+10;
const int INF=0x6fffffff>>2;
 
struct edge{
	int u,v,c,flow;
};
 
struct Dinic{
	int n,m,s,t;
	vector<edge>edges;
	vector<int>f[Maxn];
	bool vis[Maxn];
	int d[Maxn];
	int cur[Maxn];
	
	void AddEdge(int from,int to,int c){
		edges.push_back({from,to,c,0});
		edges.push_back({to,from,0,0});
		m=edges.size();
		f[from].push_back(m-2);
		f[to].push_back(m-1);
	}
	
	bool BFS(){
		memset(vis,0,sizeof(vis));
		queue<int>q;
		q.push(s);
		d[s]=0;
		vis[s]=1;
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=0;i<f[x].size();i++){
				edge &e=edges[f[x][i]];
				if(!vis[e.v]&&e.flow<e.c)
				{
					vis[e.v]=1;
					d[e.v]=d[x]+1;
					q.push(e.v);
				}
			}
		}
		return vis[t];
	}
	int DFS(int x,int a)
	{
		if(x==t||a==0)return a;
		int flow=0,r;
		for(int& i=cur[x];i<f[x].size();i++){
			edge& e=edges[f[x][i]];
			if(d[x]+1==d[e.v]&&(r=DFS(e.v,min(a,e.c-e.flow)))>0){
				e.flow+=r;
				edges[f[x][i]^1].flow-=r;
				flow+=r;
				a-=r;
				if(a==0)break;
			}
		}
		return flow;
	}
	int MaxFlow(int s,int t)
	{
		this->s=s;this->t=t;
		int flow=0;
		while(BFS())
		{
			memset(cur,0,sizeof(cur));
			flow+=DFS(s,INF);
		}
		return flow;
	}
}G;
int main()
{
	int x,y,z;
	int s,t;
	scanf("%d",&G.n);
	while(1)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(!(x|y|z))break;
		G.AddEdge(x,y,z);
	}
	scanf("%d%d",&s,&t);
	printf("%d\n",G.MaxFlow(s,t));
	return 0;
}