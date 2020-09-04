#include "bits/stdc++.h"
using namespace std;
#define DEBUG
#ifndef DEBUG
    #define N 500010
#else
    #define N 1010
#endif
int n,c[N],f[N],dp[N],g[N],ssum[N],gsum,sgum[N],ggum;
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
        gsum=ggum=0;
        if(son[u].size()){
            for(int i=0;i<son[u].size();i++){
                int k=son[u][i];
                ssum[u]+=dp[k];
                sgum[u]+=g[k];
                gsum+=ssum[k];
                ggum+=sgum[k];
            }
            dp[u]=max(ssum[u],gsum+1);
            if(ssum[u]>gsum+1){
                g[u]=sgum[u];
            }else{
                g[u]=ggum+c[u];
            }
        }else{
            ssum[u]=0;
            dp[u]=1;
            g[u]=c[u];
        }
    }
    cout<<g[1]<<endl;
    return 0;
}