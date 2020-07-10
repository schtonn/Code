#include "bits/stdc++.h"
using namespace std;
int n,p,a[1000010],dp[1000010];
int main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int mFroggie=dp[i-1];
        for(int j=i-p;j<i;j++){
            if(j<0)continue;
            mFroggie=max(mFroggie,dp[j]);
        }
        dp[i]=mFroggie+a[i];
    }
    cout<<dp[n]<<endl;
    return 0;
}