#include "bits/stdc++.h"
using namespace std;

const long long mod=1000000007,N=100010;
long long n,m,f[N<<5],dep[N<<5];

struct node{
    long long l,r;
}t[N<<5];
long long rt[N],tot;

void build(long long&id,long long l,long long r){
    id=++tot;
    if(l==r){
        f[id]=l;
        return;
    }
    long long mid=(l+r)>>1;
    build(t[id].l,l,mid);
    build(t[id].r,mid+1,r);
}

void change(long long&id,long long last,long long l,long long r,long long p,long long c){
    id=++tot;
    if(l==r){
        f[id]=c;
        dep[id]=dep[last];
        return;
    }
    t[id].l=t[last].l;t[id].r=t[last].r;
    long long mid=(l+r)>>1;
    if(p<=mid)change(t[id].l,t[last].l,l,mid,p,c);
    else change(t[id].r,t[last].r,mid+1,r,p,c);
}

long long query(long long id,long long l,long long r,long long p){
    if(l==r)return id;
    long long mid=(l+r)>>1;
    if(p<=mid)return query(t[id].l,l,mid,p);
    else return query(t[id].r,mid+1,r,p);
}

void add(long long id,long long l,long long r,long long p){
    if(l==r){
        ++dep[id];
        return;
    }
    long long mid=(l+r)>>1;
    if(p<=mid)add(t[id].l,l,mid,p);
    else add(t[id].r,mid+1,r,p);
}

long long getf(long long rt,long long x){
    long long c=query(rt,1,n,x);
    if(x==f[c])return c;
    return getf(rt,f[c]);
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    long long hash=0,op,x,y,X,Y;
    build(rt[0],1,n);
    for(long long i=1;i<=m;++i){
        cin>>op;
        if(op==1){
            rt[i]=rt[i-1];
            cin>>x>>y>>X>>Y;
            long long a=(hash*x+y)%n+1,b=(hash*X+Y)%n+1;
            long long f1=getf(rt[i],a);
            long long f2=getf(rt[i],b);
            if(f[f1]==f[f2]){
                hash=(hash*2)%mod;
                continue;
            }
            hash=(hash*2+1)%mod;
            if(dep[f1]>dep[f2])swap(f1,f2);
            change(rt[i],rt[i-1],1,n,f[f1],f[f2]);
            if(dep[f1]==dep[f2])add(rt[i],1,n,f[f2]);
        }
        if(op==2){
            cin>>x>>y;
            long long k=(hash*x+y)%i;
            rt[i]=rt[k];
        }
    }
    cout<<hash<<endl;
    return 0;
}
