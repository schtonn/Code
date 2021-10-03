#include "bits/stdc++.h"
using namespace std;
const int N=100010;
struct node{
    int v,nxt;
}e[N<<2];
int h[N],tot,kksk;
void adde(int u,int v){
    tot++;
    e[tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
int n,m,q,a[N],s[N],f[N],g[N];

void dfs1(int fa,int u,int k){
    int mx=0;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa)continue;
        dfs1(u,v,k);
        f[u]+=max(0,f[v]-k)+(!a[v]);
    }
}
void dfs2(int fa,int u){
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa)continue;
        int l=-1,r=100010,fv=f[v],fu=f[u];
        while(l<r){
            int k=(l+r)>>1;
            int c=fu-max(0,fv-g[u]+1)-(!a[v]);
            f[v]=fv+max(0,c-k)+(!a[u]);
//            cout<<u<<' '<<v<<' '<<fu<<' '<<fv<<' '<<g[u]<<' '<<c<<' '<<f[v]<<endl;
            if(f[v]>k)l=k+1;
            else r=k;
        }
        g[v]=l;
        dfs2(u,v);
    }
}
int main(){
    // freopen("query.in","r",stdin);
    // freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adde(u,v);
        adde(v,u);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!a[i])kksk=1;
    }
    int l=-1,r=100010;
    while(l<r){
        int mid=(l+r)>>1;
        memset(f,0,sizeof(f));
        dfs1(1,1,mid);
        if(f[1]>mid)l=mid+1;
        else r=mid;
    }
    g[1]=l;
    dfs2(1,1);
    // for(int i=1;i<=n;i++){
    //     cout<<g[i]<<' '<<f[i]<<endl;
    // }
    cin>>m;
    int mx=0;
    for(int i=1;i<=m;i++)cin>>s[i],mx=max(mx,g[s[i]]);
    cin>>q;
    if(!kksk){
        for(int i=1;i<=q;i++){
            cout<<"No"<<endl;
        }
        return 0;
    }
    for(int i=1;i<=q;i++){
        int k;
        cin>>k;
        if(k<mx)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}