#include "bits/stdc++.h"
using namespace std;
#define ri register int
const int N=100010;
int n,mod,ans,f1[N],f2[N][330];
int main(){
    cin>>n>>mod;
    f1[0]=1;
    int m=sqrt(n)+1;
    for(ri i=1;i<=m;i++){
        for(ri j=i;j<=n;j++){
        f1[j]=(f1[j-i]+f1[j])%mod;
        }
    }
    m++;
    f2[0][0]=1;
    for(ri i=m;i<=n;i++){
        f2[i][1]=1;
        for(ri j=2;j<=m;j++){
            f2[i][j]=(f2[i-j][j]+f2[i-m][j-1])%mod;
        }
    }
    for(ri i=0;i<=n;i++){
        for(ri j=0;j<=m;j++){
            ans=(ans+1ll*f1[i]*f2[n-i][j])%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}