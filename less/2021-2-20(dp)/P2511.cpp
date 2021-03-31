#include "bits/stdc++.h"
using namespace std;
const int N=500010,p=10007;
int n,m,a[N],sa[N],f[N],fir[N],sf[N];
bool check(int mid){
    int ret=0,cur=0;
    for(register int i=1;i<=n;i++){
        if(cur+a[i]>mid){
            cur=0;
            ret++;
            if(ret>m)return false;
        }
        cur+=a[i];
    }
    return ret<=m;
}
int DP(int x){
    int k=0;
    for(register int i=1;i<=n;i++){
        for(;k<i;k++){
            if(sa[i]-sa[k]<=x){
                fir[i]=k;
                break;
            }
        }
    }
    int ans=(sa[n]<=x);
    for(register int i=1;i<=n;i++){
    	f[i]=(sa[i]<=x);
    	sf[i]=(sf[i-1]+f[i])%p;
    }
    for(register int i=2;i<=m+1;i++){
        for(register int j=1;j<=n;j++){
            f[j]=sf[j-1];
            if(fir[j]-1>=0)f[j]=((f[j]-sf[fir[j]-1])%p+p)%p;
        }
        for(register int j=1;j<=n;j++){
            sf[j]=(sf[j-1]+f[j])%p;
        }
        ans=(ans+f[n])%p;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int l=0,r,mid;
    for(register int i=1;i<=n;i++){
        cin>>a[i];
        l=max(l,a[i]);
        sa[i]=sa[i-1]+a[i];
    }
    r=sa[n];
    while(l<r){
        mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<r<<' '<<DP(r)<<endl;
    return 0;
}