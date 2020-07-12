#include "bits/stdc++.h"
using namespace std;
int n,p,a[1010],dp[1010],r[1010],ans[1010],num;
int main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n+1;i++){
        int mFroggie=dp[i-1];
        int mFroggid=i-1;
        for(int j=i-p;j<i;j++){
            if(j<0)continue;
            if(mFroggie>dp[j]){
                mFroggie=dp[j];
                mFroggid=j;
            }
        }
        r[i]=mFroggid;
        dp[i]=mFroggie+a[i];
    }
    cout<<dp[n+1]<<endl;
    for(int i=n;i;i=r[i]){
        num++;
        ans[num]=i;
    }
    cout<<num<<endl;
    for(int i=num;i;i--){
        cout<<ans[i]<<' ';
    }
    return 0;
}