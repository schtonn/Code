#include "bits/stdc++.h"
using namespace std;
long long a,b,mod=10,ans=1;
int n;
int main(){
    // freopen("mason.in","r",stdin);
    // freopen("mason.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        ans=1;
        cin>>a;
        b=a;
        while(b){
            if(b&1)ans=ans*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}