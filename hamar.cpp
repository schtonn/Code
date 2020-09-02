#include "bits/stdc++.h"
using namespace std;
#define DEBUG
#define N 1010
int n,c[N],f[N],dp[N],g[N],ssum[N],gsum,sgum[N],ggum;
vector<int>son[N];
vector<int>order;
queue<int>q;
// int dp(int u){
//     gsum=ssum=0;
//     cout<<"and down to "<<u<<' ';
//     if(son[u].size()){
//         cout<<"which is not a leave ";
//         for(int i=0;i<son[u].size();i++){
//             ssum+=dp(son[u][i]);
//         }
//         int k=max(gsum+1,ssum);
//         cout<<" with son of "<<ssum<<" and grandson of "<<gsum<<' ';
//         gsum+=ssum;
//         cout<<"and leaving "<<u<<' ';
//         return k;
//     }else{
//         cout<<"which is a leave, so leaving "<<u<<' ';
//         return 1;
//     }
// }
int main(){
    #ifndef DEBUG
    freopen("WolfDelaymaster.in","r",stdin);
    freopen("WolfDelaymaster.out","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        cin>>f[i];
        if(i!=1)son[f[i]].push_back(i);
    }
    // cout<<dp(1)<<endl;
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
        gsum=0;
        if(son[u].size()){
            for(int i=0;i<son[u].size();i++){
                ssum[u]+=dp[son[u][i]];
                sgum[u]+=g[son[u][i]];
                gsum+=ssum[son[u][i]];
                ggum+=sgum[son[u][i]];
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