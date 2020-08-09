#include "bits/stdc++.h"
using namespace std;
#define MAXN 1010
struct node{
    int v,next;
}e[MAXN];
int h[MAXN],tot,n,d,con,s,st[MAXN];
bool vis[MAXN];
char frog;
void adde(int u,int v){
    tot++;
    e[tot].v=v;
    e[tot].next=h[u];
    h[u]=tot;
}
queue<int>q;
void dfs(int u){
    con++;
    vis[u]=1;
    for(int i=h[u];i;i=e[i].next){
        int v=e[i].v;
        if(!vis[v])dfs(v);
    }
}
void bfs(int k){
    while(!q.empty())q.pop();
    q.push(k);
    vis[k]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        s=max(s,st[u]);
        for(int i=h[u];i;i=e[i].next){
            int v=e[i].v;
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
                st[v]=st[u]+1;
            }
        }
    }
}
int main(){
    // freopen("Egalitarianism.in","r",stdin);
    // freopen("Egalitarianism.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>frog;
            if(frog=='Y'){
                adde(i,j);
            }
        }
    }
    cin>>d;
    dfs(0);
    if(con<n){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)vis[j]=0;
        for(int j=0;j<n;j++)st[j]=0;
        bfs(i);
    }
    cout<<s*d<<endl;
    return 0;
}
/*
15
NYYNNNNYYYYNNNN
YNNNYNNNNNNYYNN
YNNYNYNNNNYNNNN
NNYNNYNNNNNNNNN
NYNNNNYNNYNNNNN
NNYYNNYNNYNNNYN
NNNNYYNNYNNNNNN
YNNNNNNNNNYNNNN
YNNNNNYNNNNNYNN
YNNNYYNNNNNNNNY
YNYNNNNYNNNNNNN
NYNNNNNNNNNNNNY
NYNNNNNNYNNNNYN
NNNNNYNNNNNNYNN
NNNNNNNNNYNYNNN
1
*/