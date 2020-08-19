#include "bits/stdc++.h"
using namespace std;
const int inf=0x3f3f3f3f;
int a[1010],f[1010][1010],t[1010][1010],n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<=j;k++){
                t[i][j]+=a[k];
            }
        }
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            if(i==j)continue;
            f[i][j]=inf;
            for(int k=i;k<=j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+t[i][j]);
            }
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}