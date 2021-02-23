#include "bits/stdc++.h"
using namespace std;
const int N=100010;
struct node{
    int l,r,sum;
}t[N<<5];
int n,m,a[N],p[N],rt[N],cnt;
void build(int l,int r,int &id){
    id=++cnt;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(l,mid,t[id].l);
    build(mid+1,r,t[id].r);
}
void change(int &id,int lid,int l,int r,int pos){
    id=++cnt;
    t[id]=t[lid];
    t[id].sum++;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(pos<=mid)change(t[id].l,t[lid].l,l,mid,pos);
    else change(t[id].r,t[lid].r,mid+1,r,pos);
}
int query(int id,int lid,int l,int r,int k){
    if(l==r)return l;
    int d=t[t[id].l].sum-t[t[lid].l].sum;
    int mid=(l+r)>>1;
    if(k<=d)return query(t[id].l,t[lid].l,l,mid,k);
    else return query(t[id].r,t[lid].r,mid+1,r,k-d);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[i]=a[i];
    }
    sort(p+1,p+1+n);
    int num=unique(p+1,p+1+n)-p-1;
    cnt=0;
    build(1,num,rt[0]);
    for(int i=1;i<=n;i++){
        int pos=lower_bound(p+1,p+1+num,a[i])-p;
        change(rt[i],rt[i-1],1,num,pos);
    }
    for(int i=1;i<=m;i++){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        int pos=query(rt[r],rt[l-1],1,num,k);
        printf("%d\n",p[pos]);
    }
    return 0;
}