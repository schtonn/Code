#include "bits/stdc++.h"
using namespace std;
const long long mod=100003;
long long n,m;
long long qpow(long long a,long long b){
    long long ans=1;
    a%=mod;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int main(){
    // freopen("mason.in","r",stdin);
    // freopen("mason.out","w",stdout);
    cin>>m>>n;
    m%=mod;
    n%=mod;
    cout<<((qpow(m,n)%mod-(m*qpow(m-1,n-1)%mod))+mod)%mod;
    return 0;
}