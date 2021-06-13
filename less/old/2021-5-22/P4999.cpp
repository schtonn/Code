#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
ll l,r,ans,dp[20][20],num[20];
int a[20],len,t;
ll dfs(int need,int pos,int sum,bool limit,bool lead){
    if(!pos)return sum;
    if(!limit&&!lead&&dp[pos][sum]!=-1)return dp[pos][sum];
    int up=limit?a[pos]:9;
    ll ret=0;
    for(int i=0;i<=up;i++){
        if(lead&&!i)ret+=dfs(need,pos-1,sum,limit&&(i==up),1);
        else ret+=dfs(need,pos-1,sum+(i==need),limit&&(i==up),0);
    }
    if(!limit&&!lead)dp[pos][sum]=ret;
    return ret;
}
void solvel(ll x){
    len=0;
    while(x)a[++len]=x%10,x/=10;
    for(int i=1;i<=9;i++){
        memset(dp,-1,sizeof(dp));
        num[i]=(num[i]-dfs(i,len,0,1,1)+mod)%mod;
    } 
} 
void solver(ll x){
    len=0;
    while(x)a[++len]=x%10,x/=10;
    for(int i=1;i<=9;i++){
        memset(dp,-1,sizeof(dp));
        num[i]=dfs(i,len,0,1,1)%mod;
    } 
} 
int main(){
    cin>>t;
    while(t--){
        ans=0;
        scanf("%lld%lld",&l,&r);
        solver(r);
        solvel(l-1);
        for(int i=1;i<=9;i++){
            ans=((ans+i*num[i]+mod)%mod+mod)%mod;
        }
        cout<<ans<<endl;
    } 
    return 0;
} 