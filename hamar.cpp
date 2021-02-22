#include"bits/stdc++.h"
using namespace std;
struct node{
    int l,r,c,lazy;
}t[10000010];
long long ll[40000001],rr[40000001],cnt,n,m,i,l1,r1,v,val,q,a[1000001],he[1000001];
void xiafang(long long u){
    cnt++;
    ll[u]=cnt;
    t[cnt].l=t[u].l;
    t[cnt].r=(t[u].l+t[u].r)/2;
    t[cnt].lazy=t[u].c*(t[cnt].r-t[cnt].l+1);
    t[cnt].c=t[u].c;
    cnt++;
    rr[u]=cnt;
    t[cnt].l=(t[u].l+t[u].r)/2+1;
    t[cnt].r=t[u].r;
    t[cnt].lazy=t[u].c*(t[cnt].r-t[cnt].l+1);
    t[cnt].c=t[u].c;
    t[u].c=0;
}
void build(long long u,long long l1,long long r1){
    t[u].l=l1;
    t[u].r=r1;
    if(l1==r1){
        t[u].lazy=a[l1];
        return;
    }
    cnt++;
    ll[u]=cnt;
    build(ll[u],l1,(l1+r1)/2);
    cnt++;
    rr[u]=cnt;
    build(rr[u],(l1+r1)/2+1,r1);
    t[u].lazy=t[ll[u]].lazy+t[rr[u]].lazy;
}
void jia(long long mo,long long u,long long l1,long long r1,long long k){
    t[u].l=t[mo].l;
    t[u].r=t[mo].r;
    if(t[u].l>=l1&&t[u].r<=r1){
        t[u].lazy=k*(t[u].r-t[u].l+1);
        t[u].c=k;
        return;
    }
    if(t[mo].c)xiafang(mo);
    if(r1<=(t[u].l+t[u].r)/2){
        rr[u]=rr[mo];
        cnt++;
        ll[u]=cnt;
        jia(ll[mo],ll[u],l1,r1,k);
        t[u].lazy=t[ll[u]].lazy+t[rr[u]].lazy;
    }else if(l1>(t[u].l+t[u].r)/2){
        ll[u]=ll[mo];
        cnt++;
        rr[u]=cnt;
        jia(rr[mo],rr[u],l1,r1,k);
        t[u].lazy=t[ll[u]].lazy+t[rr[u]].lazy;
    }else{
        cnt++;
        ll[u]=cnt;
        jia(ll[mo],ll[u],l1,r1,k);
        cnt++;
        rr[u]=cnt;
        jia(rr[mo],rr[u],l1,r1,k);
        t[u].lazy=t[ll[u]].lazy+t[rr[u]].lazy;
    }
}
long long qui(long long u,long long l1,long long r1){
    if(t[u].l>r1||t[u].r<l1)return 0;
    if(t[u].l>=l1&&t[u].r<=r1)return t[u].lazy;
    if(t[u].c)xiafang(u);
    return (qui(ll[u],l1,r1)+qui(rr[u],l1,r1))%998244353;
}
int main(){
    he[0]=1;
    cnt=1;
    cin>>n>>m;
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    build(1,1,n);
    for(i=1;i<=m;i++){
        scanf("%lld%lld",&v,&q);
        if(q==1){
            cnt++;
            he[i]=cnt;
            scanf("%lld%lld%lld",&l1,&r1,&val);
            jia(he[v],he[i],l1,r1,val);
        }else{
            scanf("%lld%lld",&l1,&r1);
            he[i]=he[v];
            printf("%lld\n",qui(he[v],l1,r1)%998244353);
        }
    }
    return 0;
}