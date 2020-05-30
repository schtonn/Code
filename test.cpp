#include "bits/stdc++.h"
using namespace std;
const int N=1<<5;
int n,m,e[25][25];
bool dp[N][25];//dp[i][j]表示状态为i，最后到达j点有没有路径
int g[N][25];
int special[N][3];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u][v]=true;
    }
    dp[1][1]=true;
    for(int s=1;s<(1<<n);++s){
        for(int p=1;p<=n;++p){
            if(s&(1<<(p-1))==0)continue;
            for(int q=1;q<=n;++q){
                if(s&(1<<(q-1))==0)continue;
                if(!e[q][p])continue;
                if(dp[s^(1<<(p-1))][q]){
                    dp[s][p]=true;
                    g[s][p]=q;
                }
            }
        }
    }
    int s=(1<<n)-1;
    bool flag;
    do{
        flag=1;
        for(int i=1;i<=n;i++){
            if(g[s][i]>0){
                cout<<g[s][i]<<' ';
                s-=(1<<(g[s][i]-1));
                flag=0;
                break;
            }
        }
    }while(s!=1&&flag==0);
    return 0;
}