#include "bits/stdc++.h"
using namespace std;
#define lson id<<1
#define rson id<<1|1
#define N 1000010
int n,a[N],cnt,ans[N],num[N];
struct node{
    int l,r,num;
}tG[N],tM[N];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void buildGcd(int id,int l,int r){
    tG[id].l=l;
    tG[id].r=r;
    if(l==r){
        tG[id].num=a[l];
        return;
    }
    int mid=(l+r)>>1;
    buildGcd(lson,l,mid);
    buildGcd(rson,mid+1,r);
    tG[id].num=gcd(tG[lson].num,tG[rson].num);
}
void buildMin(int id,int l,int r){
    tM[id].l=l;
    tM[id].r=r;
    if(l==r){
        tM[id].num=a[l];
        return;
    }
    int mid=(l+r)>>1;
    buildMin(lson,l,mid);
    buildMin(rson,mid+1,r);
    tM[id].num=min(tM[lson].num,tM[rson].num);
}
inline int queryGcd(int id,int L,int R){
    if(tG[id].l>=L&&tG[id].r<=R)return tG[id].num;
    if(tG[id].r<L||tG[id].l>R)return 0;
    return gcd(queryGcd(lson,L,R),queryGcd(rson,L,R));
}
inline int queryMin(int id,int L,int R){
    if(tM[id].l>=L&&tM[id].r<=R)return tM[id].num;
    if(tM[id].r<L||tM[id].l>R)return 0x3f3f3f3f;
    return min(queryMin(lson,L,R),queryMin(rson,L,R));
}
inline int check(int mid){
    int ret=0;
    memset(num,0,sizeof(num));
    for(int i=1;i<=n-mid;i++){
        // cout<<i<<'-'<<i+mid<<endl;
        // cout<<queryMin(1,i,i+mid)<<' '<<queryGcd(1,i,i+mid)<<endl;
        if(queryMin(1,i,i+mid)==queryGcd(1,i,i+mid)){
            num[++ret]=i;
        }
    }
    return ret;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int l=0,r=n;
    buildGcd(1,1,n);
    buildMin(1,1,n);
    while(l<=r){
        int mid=(l+r)/2,p;
        if(p=check(mid)){
            cnt=p;
            l=mid+1;
            for(int i=1;i<=cnt;i++)ans[i]=num[i];
        }else r=mid-1;
    }
    cout<<cnt<<' '<<l-1<<endl;
    for(int i=1;i<=cnt;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
/*
必做：P1419，P2115，P3500，CF732D，P2985，CF359D
其他：P4951，P3576，CF553D，P2218
*/