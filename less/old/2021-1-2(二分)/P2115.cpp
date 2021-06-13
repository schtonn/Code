//https://www.luogu.com.cn/record/44717629
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef double dou;
#define N 100010
const dou eps=1e-5;
ll n,S,T,a[N];
dou post[N],pre[N];
dou t[N];
dou max(dou a,dou b){return a>b?a:b;}
dou min(dou a,dou b){return a<b?a:b;}
bool check(dou mid){
    t[0]=0;
    for(int i=1;i<=n;i++){
        t[i]=t[i-1]+a[i]-mid;
    }
    for(int i=n-1;i>=2;i--)post[i]=max(post[i+1],t[i]);
    for(int i=2;i<=n-1;i++)pre[i]=min(pre[i-1],t[i]);
    for(int i=2;i<=n-1;i++){
        if(post[i]-pre[i-1]>t[n])return false;
    }
    return true;
}
int main(){
    cin>>n;
    post[n]=-INT_MAX;
    pre[1]=INT_MAX;
    for(int i=1;i<=n;i++)cin>>a[i];
    dou l=0,r=(a[1]+a[n])/2;
    while(r-l>eps){
        dou mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    printf("%.3lf",l);
    return 0;
}
/*
必做：P1419，P2115，P3500，CF732D，P2985，CF359D
其他：P4951，P3576，CF553D，P2218
*/