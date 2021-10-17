#include "bits/stdc++.h"
using namespace std;
const int N=100;
int n,m,u,v,f[N][N][N],e[N][N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            e[i][j]=0x3f3f3f3f;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        f[u][v][0]=e[u][v]=1;
    }
    for(int k=1;k<=100;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int t=1;t<=n;t++){
                    if(f[i][t][k-1]&f[t][j][k-1]){
                        f[i][j][k]=1;
                        e[i][j]=1;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
            }
        }
    }
    cout<<e[1][n]<<endl;
    return 0;
}