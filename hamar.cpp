#include "bits/stdc++.h"
using namespace std;
int n,a[100010],dp[100010];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[1]=a[1];
    for(int i=2;i<=n;i++){
        dp[i]=max(dp[i-1],dp[i-2])+a[i];
    }
    cout<<dp[n]<<endl;
    return 0;
}