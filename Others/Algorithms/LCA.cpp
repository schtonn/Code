#include "bits/stdc++.h"
using namespace std;
const int N=500010;
int n,q,tot,d[N],fa[N][50],lg[N],h[N];
struct node{
    int v,nxt;
}e[N];
void adde(int u,int v){
    e[++tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
void dfs(int u,int f){
    d[u]=d[f]+1;
    fa[u][0]=f;
    for(int i=1;(1<<i)<=d[u];i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(int i=h[u];i;i=e[i].nxt){
		if(e[i].v!=f)dfs(e[i].v,u);
    }
}
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y])x=fa[x][lg[d[x]-d[y]]-1];
    if(x==y)return x;
    for(int k=lg[d[x]]-1;k>=0;k--){
		if(fa[x][k]!=fa[y][k]){
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return fa[x][0];
}
int dist(int x,int y){
    int z=lca(x,y);
    return d[x]-d[z]+d[y]-d[z];
}
int main(){
    return 0;
}