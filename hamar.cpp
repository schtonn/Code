#include "bits/stdc++.h"
using namespace std;
#define DEBUG
#ifndef DEBUG
    #define N 500010
#else
    #define N 1010
#endif
int n,c[N],f[N],dp[N][2],sum0,sum1,sgum[N],ggum;
//dp[u][0]:u为根不选u
//dp[u][1]:u为根选u
vector<int>son[N];
vector<int>order;
queue<int>q;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        cin>>f[i];
        if(i!=1)son[f[i]].push_back(i);
    }
    q.push(1);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        order.push_back(v);
        for(int i=0;i<son[v].size();i++){
            q.push(son[v][i]);
        }
    }
    for(int i=n-1;i>=0;i--){
        int u=order[i];
        sum0=sum1=0;
        for(int i=0;i<son[u].size();i++){
            sum0+=max(dp[son[u][i]][0],dp[son[u][i]][1]);
            sum1+=dp[son[u][i]][0];
        }
        dp[u][0]=sum0;
        dp[u][1]=sum1+1;
    }
    cout<<max(dp[1][0],dp[1][1]);
    return 0;
}