#include "bits/stdc++.h"
using namespace std;
const int mod=10000;
int f[1010][1010];
int g[1010][1010];
int n,k;
int main(){
    cin>>n>>k;
    f[1][0]=1;
    for(int i=0;i<=k;i++)g[1][i]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=min(n*(n-1)/2,k);j++){
            if(j-i<0)f[i][j]=g[i-1][j];
            else f[i][j]=(g[i-1][j]-g[i-1][j-i]+mod)%mod;
        }
        g[i][0]=f[i][0];
        for(int j=1;j<=k;j++)g[i][j]=(g[i][j-1]+f[i][j])%mod;
    }
    cout<<f[n][k]<<endl;
    return 0;
}