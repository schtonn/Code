#include "bits/stdc++.h"
using namespace std;
const int N=100010,M=100010;
struct node{
    int v,nxt;
}e[N<<2];
int n,m,h[N],in[N],st[N],tot;
void adde(int u,int v){
    tot++;
    e[tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adde(u,v);
        in[v]++;
    }
    priority_queue<int,vector<int>,greater<int> >q;
    for(int i=1;i<=n;i++){
        if(!in[i])q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int u=q.top();
        q.pop();
        for(int i=h[u];i;i=e[i].nxt){
            int v=e[i].v;
            in[v]--;
            if(!in[v])q.push(v);
        }
        h[u]=0;
        st[cnt]=u;
        cnt++;
    }
    if(cnt!=n)cout<<"No"<<endl;
    else{
        for(int i=0;i<n;i++){
            cout<<st[i]<<' ';
        }
    }
    return 0;
}