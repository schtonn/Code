#include "bits/stdc++.h"
using namespace std;
int l[3],d[3][100],pos[100][2];
long long pw[100],ans;
void pop(int x){
//	cout<<"P"<<x<<endl;
	for(int i=0;i<l[x];i++)d[x][i]=d[x][i+1],pos[d[x][i]][1]=i;
	l[x]--;
}
void push(int x,int p){
//	cout<<"U"<<x<<' '<<p<<endl;
	for(int i=l[x];i>0;i--)d[x][i]=d[x][i-1],pos[d[x][i]][1]=i;
	d[x][0]=p;
	pos[p][0]=x;
	pos[p][1]=0;
	l[x]++;
}
int get(int a,int b){
	for(int i=0;i<3;i++)if(i!=a&&i!=b)return i;
	return 0;
}
void mvstack(int v,int p){
//	cout<<"S"<<v<<' '<<p<<endl;
	int u=pos[v][0],n=pos[v][1]+1;
	stack<int>s;
	for(int i=1;i<=n;i++)s.push(d[u][0]),pop(u);
	while(!s.empty())push(p,s.top()),s.pop();
	ans+=pw[n]-1;
}
void mv(int v,int p){
//	cout<<v<<">>"<<p+1<<endl;
	if(v==0)getchar();
	int u=pos[v][0];
	if(u==p)return;
	int q=get(u,p);
	int flag=1;
	while(flag){
		flag=0;
		while(pos[v][1]!=0){
			flag=1;
			if(d[q][0]>d[u][pos[v][1]-1]){
				mvstack(d[u][pos[v][1]-1],q);
			}
			else mv(d[u][pos[v][1]-1],q);
		}
		while(d[p][0]&&d[p][0]<v){
			flag=1;
			int g=0;
			while(d[p][g]&&d[p][g]<v)g++;
			if(d[q][0]>d[p][g-1]||!d[q][0]){
				mvstack(d[p][g-1],q);
			}
			else mv(d[p][g-1],q);
		}
	}
	pop(u);
	push(p,v);
	ans++;
	return;
}
int main(){
	for(int i=0;i<3;i++)cin>>l[i];
	for(int i=0;i<3;i++){
		for(int j=0;j<l[i];j++){
			cin>>d[i][j];
			pos[d[i][j]][0]=i;
			pos[d[i][j]][1]=j;
		}
	}
	pw[0]=1;
	for(int i=1;i<=70;i++)pw[i]=pw[i-1]*2;
	for(int i=l[0]+l[1]+l[2];i>0;i--){
		mv(i,2);
	}
	cout<<ans<<endl;
	return 0;
}