#include "bits/stdc++.h"
using namespace std;
const long long p=998244353;
const long long maxn=5000010;
long long t,n,k,g[maxn],h[maxn],c[maxn],f[maxn];
long long qpow(long long a,long long n){
    long long ans=1;
    while(n){
        if(n&1) ans=ans*a%p;
        a=a*a%p;
        n>>=1;
    }
    return ans%p;
}
int main(){
    g[1]=1;
    for(long long i=2;i<maxn;i++){
        g[i]=(p-p/i)*g[p%i]%p;
    }
    h[0]=1,c[0]=1;
    for(long long i=1;i<maxn;i++){
        h[i]=h[i-1]*i%p;
        c[i]=c[i-1]*g[i]%p;
    }
    f[0]=1,f[1]=0;
    for(long long i=2;i<maxn;i++){
        f[i]=2*i*(2*i-2)%p*(f[i-1]%p+(2*i-2)*f[i-2]%p)%p;
    }
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long ans=h[n]*c[k]%p*c[n-k]%p*h[n]%p*c[n-k]%p*qpow(2,k)%p*f[n-k]%p;
        cout<<ans%p<<endl;
    }
    return 0;
}