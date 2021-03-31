//https://www.luogu.com.cn/record/45380882
#include "bits/stdc++.h"
using namespace std;
const int N=15,mod=100000000;
int n,m,hole,a[N],f[N][5000];
int t(int x){
    return x&(x<<1);
}
int main(){
    f[0][0]=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>hole;
            a[i]<<=1;
            a[i]|=hole;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<m);j++){
            if(t(j)||(j&a[i])!=j)continue;
            cout<<"OK"<<endl;
            for(int k=0;k<(1<<m);k++){
                if(t(k)||k&j)continue;
                f[i][j]=(f[i][j]+f[i-1][k])%mod;
                cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j]<<endl;
            }
        }
    }
    int ans=0;
    for(int i=0;i<(1<<m);i++){
        ans=(ans+f[n][i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}