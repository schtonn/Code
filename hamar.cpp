#include "bits/stdc++.h"
using namespace std;
#define DEBUG
#ifndef DEBUG
    #define N 500010
#else
    #define N 1010
#endif
int n,c[N],f[N],dp[N][2],ka[N],kb[N],sum0,sum1,sgum[N],ggum;
//dp[u][0]:u为根不选u
//dp[u][1]:u为根选u
vector<int>son[N];
vector<int>ansa[N];
vector<int>ansb[N];
vector<int>order;
vector<int>Null;
queue<int>q;
bool cmd(int a,int b){
    return a<b;
}
int main(){
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>f[i];
        son[f[i]].push_back(i);
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
    for(int t=n-1;t>=0;t--){
        int u=order[t];
        sum0=sum1=0;
        for(int i=0;i<son[u].size();i++){
            sum0+=max(dp[son[u][i]][0],dp[son[u][i]][1]);
            if(dp[son[u][i]][0]>dp[son[u][i]][1]){
                for(int j=0;j<ansa[son[u][i]].size();j++){
                    ansa[u].push_back(ansa[son[u][i]][j]);
                }
            }else{
                for(int j=0;j<ansb[son[u][i]].size();j++){
                    ansa[u].push_back(ansb[son[u][i]][j]);
                }
            }
            sum1+=dp[son[u][i]][0];
            for(int j=0;j<ansa[son[u][i]].size();j++){
                ansb[u].push_back(ansa[son[u][i]][j]);
            }
            Null.swap(ansa[son[u][i]]);
            Null.swap(ansb[son[u][i]]);
        }
        ansb[u].push_back(u);
        dp[u][0]=sum0;
        dp[u][1]=sum1+1;
    }
    if(dp[1][0]>dp[1][1]){
        for(int i=0;i<ansa[1].size();i++){
            ka[i]=ansa[1][i];
        }
        sort(ka,ka+ansa[1].size());
        for(int i=0;i<ansa[1].size();i++){
            cout<<ka[i]<<' ';
        }
    }else{
        for(int i=0;i<ansb[1].size();i++){
            kb[i]=ansb[1][i];
        }
        sort(kb,kb+ansb[1].size());
        for(int i=0;i<ansb[1].size();i++){
            cout<<kb[i]<<' ';
        }
    }
    return 0;
}