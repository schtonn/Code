#include "bits/stdc++.h"
using namespace std;
int n,a[1010],dp[1010],r[1010],ansr[1010];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=1;
    }
    int ans=1,ansid=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i]){
                if(dp[i]<dp[j]+1){
                    r[i]=j;
                }
                dp[i]=max(dp[i],dp[j]+1);
                if(ans<dp[i])ansid=i;
                ans=max(ans,dp[i]);
            }
        }
    }
    cout<<ans<<endl;
    int num=0;
    for(int i=ansid;i>0;i=r[i]){
        num++;
        ansr[num]=i;
    }
    for(int i=num;i>0;i--){
        cout<<ansr[i]<<' ';
    }
    return 0;
}