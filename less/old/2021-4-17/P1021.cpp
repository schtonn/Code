#include "bits/stdc++.h"
using namespace std;
int a[20],n,k,ans[20],maxn;
int f[50000];
int dp(int t){
    f[0]=0;
    for(int i=1;i<=a[t]*n;i++)f[i]=50000;
    for(int i=1;i<=t;i++){
        for(int j=a[i];j<=a[t]*n;j++){
            f[j]=min(f[j],f[j-a[i]]+1);
        }
    }
    for(int i=1;i<=a[t]*n;i++){
        if(f[i]>n)return i-1;
    }
    return a[t]*n;
}
void dfs(int t,int mx){
    if(t==k+1){
        if(mx>maxn){
            maxn=mx;
            for(int i=1;i<=t-1;i++)ans[i]=a[i];
        }
        return;
    }
    for(int i=a[t-1]+1;i<=mx+1;i++){
        a[t]=i;
        int x=dp(t);
        dfs(t+1,x);
    }
}
int main(){
    cin>>n>>k;
    dfs(1,0);
    for(int i=1;i<=k;i++)cout<<ans[i]<<" ";
    cout<<endl;
    cout<<"MAX="<<maxn<<endl;
    return 0;
}