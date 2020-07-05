#include "bits/stdc++.h"
using namespace std;
int n,m,a[1010][1010],dp[1010][1010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    dp[1][1]=a[1][1];
    for(int i=2;i<=n;i++){
        dp[i][1]=dp[i-1][1]+a[i][1];
    }
    for(int j=2;j<=m;j++){
        dp[1][j]=dp[1][j-1]+a[1][j];
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}