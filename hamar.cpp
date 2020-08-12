#include "bits/stdc++.h"
using namespace std;
const int mod=1000000007;
int n,ans[1000010],dp[1000010];
int main(){
    // freopen("TrafficCongestion.in","r",stdin);
    // freopen("TrafficCongestion.out","w",stdout);
    cin>>n;
    ans[0]=ans[1]=dp[0]=1;
    dp[1]=2;
    for(int i=2;i<=n;i++){
        ans[i]=(2*dp[i-2]+1)%mod;
        dp[i]=(dp[i-1]+ans[i])%mod;
    }
    cout<<ans[n]<<endl;
    return 0;
}