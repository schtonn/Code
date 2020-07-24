#include "bits/stdc++.h"
using namespace std;
int n,W,sum,ans,w[1010],g[10010][2],gcnt=1,gg[1010],ggcnt=1,cnt;
bool dp[1000010];
bool ggg(int a,int b){
    for(int i=1;i<gcnt;i++){
        if(g[i][0]==a&&g[i][1]==b)return 1;
    }
    return 0;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    cin>>W;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        sum+=w[i];
        for(int j=W;j>=0;j--){
            if(j>=w[i]&&dp[j-w[i]]){
                g[gcnt][0]=i;
                g[gcnt++][1]=j;
            }
            dp[j]=max(j>=w[i]?dp[j-w[i]]:false,dp[j]);
        }
    }
    for(int i=W;i>=0;i--){
        if(dp[i]){
            ans=i;
            cout<<i<<endl;
            break;
        }
    }
    cnt=n;
    while(ans){
        if(ggg(cnt,ans)){
            gg[ggcnt++]=cnt;
            ans-=w[cnt];
        }
        cnt--;
    }
    sort(gg+1,gg+ggcnt);
    cout<<ggcnt-1<<endl;
    for(int i=1;i<ggcnt;i++){
        cout<<gg[i]<<' ';
    }
    return 0;
}