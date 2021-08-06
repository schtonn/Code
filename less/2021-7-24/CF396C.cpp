#include "bits/stdc++.h"
typedef long long ll;
using namespace std;
const ll N=300010,mod=1000000007;
ll n,m,tot,cnt,v[N],h[N],nxt[N];
ll dep[N],d[N],siz[N];
ll t[2][N];
ll lowbit(ll x){
    return x&-x;
}
void change(ll x,ll c,ll k){
    for(ll i=x;i<=n;i+=lowbit(i)){
        t[k][i]=(t[k][i]+c+mod)%mod;
    }
}
ll query(ll x){
    ll y=0,z=0;
    for(ll i=d[x];i;i-=lowbit(i))y+=t[0][i],z+=t[1][i];
    return (y-(z*dep[x]%mod)+mod)%mod;
}
void dfs(ll u){
    d[u]=++cnt;
    siz[u]=1;
    for(ll i=h[u];i;i=nxt[i]){
        dep[v[i]]=dep[u]+1;
        dfs(v[i]);
        siz[u]+=siz[v[i]];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(ll i=2;i<=n;++i){
        ll u;
        cin>>u;
        v[++tot]=i;
        nxt[tot]=h[u],h[u]=tot;
    }
    dep[1]=1;
    dfs(1);
    cin>>m;
    while(m--){
        ll op,v;
        cin>>op>>v;
        if(op==1){
            ll x,k;
            cin>>x>>k;
            change(d[v],x+dep[v]*k,0);
            change(d[v]+siz[v],-x-dep[v]*k,0);
            change(d[v],k,1);
            change(d[v]+siz[v],-k,1);
        }else{
            cout<<(query(v)+mod)%mod<<endl;
        }
    }
    return 0;
}