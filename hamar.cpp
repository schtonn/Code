#include "bits/stdc++.h"
using namespace std;
#define N 100010
struct node{
    int v,next;
}e[N];
int n,m,u,v,tot,h[N],in[N],ans[N],cnt;
void adde(int u,int v){
    tot++;
    e[tot].v=v;
    e[tot].next=h[u];
    h[u]=tot;
}
priority_queue<int,vector<int>,greater<int> >q;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        if(u==v)goto no;
        adde(u,v);
        in[v]++;
    }
    for(int i=1;i<=n;i++){
        if(!in[i])q.push(i);
    }
    while(!q.empty()){
        u=q.top();
        q.pop();
        ans[++cnt]=u;
        for(int i=h[u];i;i=e[i].next){
            v=e[i].v;
            in[v]--;
            if(!in[v])q.push(v);
        }
    }
    no:
    if(cnt<n){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}