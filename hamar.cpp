#include "bits/stdc++.h"
using namespace std;
const int N=260;
int n,m,q,a[260][260];
struct node{
    int v,nxt;
}e[N*N<<2];
struct pos{
    int x,y;
}obs[N*N];
int h[N*N<<2],tot;
int p2i(int x,int y){
    return x*(n+1)+y;
}
pos i2p(int k){
    return pos{k/(n+1),k%(n+1)};
}
void adde(int u,int v){
    if(u==v)return;
    tot++;
    e[tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
void ext(int x,int y){
    if(!a[x-1][y])for(int i=x-2;!a[i][y]&&i>=0;i--){
        adde(p2i(i,y),p2i(x-1,y));
    }
    if(!a[x+1][y])for(int i=x+2;!a[i][y]&&i<=n;i++){
        adde(p2i(i,y),p2i(x+1,y));
    }
    if(!a[x][y-1])for(int i=y-2;!a[x][i]&&i>=0;i--){
        adde(p2i(x,i),p2i(x,y-1));
    }
    if(!a[x][y+1])for(int i=y+2;!a[x][i]&&i<=n;i++){
        adde(p2i(x,i),p2i(x,y+1));
    }
}
int main(){
    freopen("ball.in","r",stdin);
    freopen("ball.out","w",stdout);
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        obs[i].x=x;
        obs[i].y=y;
        a[obs[i].x][obs[i].y]=1;
    }
    for(int i=1;i<=n;i++){
        obs[++m]=pos{0,i};
        obs[++m]=pos{i,0};
        obs[++m]=pos{n+1,i};
        obs[++m]=pos{i,n+1};
        a[0][i]=a[i][0]=a[n+1][i]=a[i][n+1]=1;
    }
    for(int i=1;i<=m;i++){
        ext(obs[i].x,obs[i].y);
    }
    int sx,sy,tx,ty;
    for(int i=1;i<=q;i++){
        cin>>sx>>sy>>tx>>ty;
        /*
        r98ccry23r8y938r939r8uc59t79eruxjeifnehdhuixjaluhu4rkwcr
        3rw3
        r
        wrw
        r
        34rqwerw34tcw45
        r
        tw4q!!!!!!!!!!!!!!!!!!!3
        cw5cwxd4qeiq9xjer8uq9fdhqi39
        */
    }
    return 0;
}
/*
4 4 3
2 2
2 4
3 2
4 4
*/