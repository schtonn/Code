#include "bits/stdc++.h"
using namespace std;
long long n,m,mop[100][100];
int main(){
    cin>>n>>m;
    mop[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>1)mop[i][j]+=mop[i-1][j];
            if(j>1)mop[i][j]+=mop[i][j-1];
            if(i%2==0&&j%2==0)mop[i][j]=0;
            // cout<<i<<j;
            // if(((i-1)%2)||(j%2)||i==1){
            //     cout<<"Y";
            //     mop[i][j]+=mop[i-1][j];
            // }
            // if((i%2)||((j-1)%2)||j==1){
            //     cout<<"K";
            //     mop[i][j]+=mop[i][j-1];
            // }
            // cout<<endl;
            // mop[i][j]+=((i-1)%2)||(j%2)?mop[i-1][j]:0;
            // mop[i][j]+=(i%2)||((j-1)%2)?mop[i][j-1]:0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<mop[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<mop[n][m];
    return 0;
}