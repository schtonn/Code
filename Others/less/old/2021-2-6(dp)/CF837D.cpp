#include "bits/stdc++.h"
using namespace std;
const int N=210;
int n,m,a,c2[N],c5[N],f[N][10010];
int main(){
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        while(a%2==0){a/=2;c2[i]++;}
        while(a%5==0){a/=5;c5[i]++;}
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            for(int k=10000;k>=c5[i];k--){
                if(f[j-1][k-c5[i]]!=-1)f[j][k]=max(f[j][k],f[j-1][k-c5[i]]+c2[i]);
            }
        }
    }
    int maxx=0;
    for(int i=1;i<10000;i++){
        maxx=max(maxx,min(i,f[m][i]));
    }
    cout<<maxx<<endl;
    return 0;
}