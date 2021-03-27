#include "bits/stdc++.h"
using namespace std;
const long long mod=1e9+7;
long long n,k,a[510];
long long ans;
inline long long f(long long x){
    long long ret=0,p=1;
    for(long long i=0;i<k;i++){
        ret=(ret+a[i]*p)%mod;
        p=(p*x)%mod;
    }
    return ret;
}
inline void work(long long l,long long r,bool fir){
    if(l==r){
        if(fir&&l<n)ans=(ans+f(l))%mod;
        return;
    }
    long long mid=(l+r)>>1;
    work(l,mid,fir);
    work(mid+1,r,!fir);
}
int main(){
    ios::sync_with_stdio(false);
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    char c;
    long long maxx=1;
    while((c=getchar())!='\n'){
        maxx=(maxx*2)%mod;
        n=(n*2)%mod;
        n+=c-'0';
    }
    cin>>k;
    for(long long i=0;i<k;i++){
        cin>>a[i];
    }
    work(0,maxx-1,0);
    cout<<ans%mod<<endl;
    return 0;
}
/*
1001011001101001
16
1 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1
*/