#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll inf=114514,N=1010,mod=998244353;
ll son[N][2],v[N],rnd[N],s[N],root,t,sum,B;
ll brand(){
	return rand()<<16|rand();	
}
void update(ll p){
    s[p]=s[son[p][0]]+s[son[p][1]]+1;
}
void rotate(ll &p,bool op){
    ll a=son[p][!op];
    son[p][!op]=son[a][op];
    son[a][op]=p;
    update(p);
    update(a);
    p=a;
}
void insert(ll &p,ll vp){
    if(!p){
        p=++t;
        v[p]=vp;
        rnd[p]=brand();
        s[p]=1;
        return;
    }
    s[p]++;
    bool op=vp>v[p];
    insert(son[p][op],vp);
    if(rnd[son[p][op]]>rnd[p])rotate(p,!op);
}
void del(ll &p,ll vp){
    if(!p)return;
    if(vp==v[p]){
        if(son[p][0]&&son[p][1]){
            bool op=rnd[son[p][0]]>rnd[son[p][1]];
            rotate(p,op),del(son[p][op],vp);
        }
        else{
            p=son[p][0]|son[p][1]; 
            return;
        }
    }
    else del(son[p][vp>v[p]],vp);
    update(p);
}
ll pre(ll p,ll vp){
    if(!p)return -inf;
    if(vp>v[p])return max(pre(son[p][1],vp),v[p]);
    else return pre(son[p][0],vp);
}
ll erp(ll p,ll vp){
    if(!p)return inf;
    if(vp<v[p])return min(erp(son[p][0],vp),v[p]);
    else return erp(son[p][1],vp);
}
int main(){
    srand(114514);
    ll n,m,k,rt=0;
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++){
        ll v;
        cin>>v;
        insert(rt,v);
        sum=(sum+v)%mod;
    }
    for(ll i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        B-=x;
        sum=(sum+x*n)%mod;
        ll p=pre(rt,B+1);
        while(p!=-inf){
            del(rt,p);
            n--;
            sum=(sum-p+B+mod)%mod;
            p=pre(rt,B+1);
        }
        p=erp(rt,k+B);
        while(p!=inf){
            del(rt,p);
            insert(rt,k+B);
            for(ll i=0;i<p-k-B;i++)insert(rt,1+B);
            n+=p-k-B;
            p=erp(rt,k+B);
        }
        if(y){
            insert(rt,y+B);
            sum=(sum+y)%mod;
            n++;
        }
        cout<<sum%mod<<endl;
    }
    return 0;
}