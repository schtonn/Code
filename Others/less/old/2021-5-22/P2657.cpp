#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int a[35];
ll dp[35][15];
ll dfs(int pos,int pre,bool lead,bool limit){
    if(pos==-1)return 1;
    if(!limit&&!lead&&dp[pos][pre]!=-1)return dp[pos][pre];
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;i++){
        if(abs(i-pre)>=2){
            if(lead&&i==0){
                ans+=dfs(pos-1,100,1,limit&&(i==up));
            }else{
                ans+=dfs(pos-1,i,0,limit&&(i==up));
            }
        }
    }
    if(!limit&&!lead)dp[pos][pre]=ans;
    return ans;
}
ll solve(ll x){
    int pos=0;
    while(x){
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,100,1,1);
}
int main(){
    memset(dp,-1,sizeof(dp));
    ll L,R;
    cin>>L>>R;
    cout<<solve(R)-solve(L-1)<<endl;
    return 0;
}