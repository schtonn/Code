#include "bits/stdc++.h"
using namespace std;
long long a,b,mod,ans;
int main(){
    // freopen("mason.in","r",stdin);
    // freopen("mason.out","w",stdout);
    cin>>a>>b>>mod;
    a%=mod;
    ans=1%mod;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    cout<<ans<<endl;
    return 0;
}