#include "bits/stdc++.h"
using namespace std;
int n,m;
int B[30005],P[30005];
vector<int>doge[30005];
bitset<30005>vis[30005];
struct node{
    int u,v,c;
};
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-')w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())
        s=(s<<1)+(s<<3)+(ch^48);
    return(w==-1?-s:s);
}
int bfs(){
    deque<node>q;
    q.push_back((node){B[0],P[0],0});
    while(!q.empty()){
        node now=q.front();
        q.pop_front();
        int u=now.u,c=now.c,v=now.v;
        if(u==B[1])return c;
        if(vis[u][v])continue;
        vis[u][v]=1;
        for(int i=0;i<doge[u].size();i++){
            q.push_front((node){u,doge[u][i],c});
        }
        if(u>=v)q.push_back((node){u-v,v,c+1});
        if(u+v<n)q.push_back((node){u+v,v,c+1});
    }
    return-1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        B[i]=read();
        P[i]=read();
        doge[B[i]].push_back(P[i]);
    }
    cout<<bfs();
    return 0;
}