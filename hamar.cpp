#include "bits/stdc++.h"
using namespace std;
long long n,a[1000010],dp[1000010];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=0;
    dp[1]=a[1];
    dp[2]=max(dp[0],dp[1])+a[2];
    dp[3]=max(max(dp[0],dp[1]),dp[2])+a[3];
    for(int i=4;i<=n;i++){
        dp[i]=max(max(max(dp[i-1],dp[i-2]),dp[i-3]),dp[i-4])+a[i];
    }
    cout<<dp[n]<<endl;
    return 0;
}