#include "bits/stdc++.h"
using namespace std;
const int N=5010;
int n,m,w[N],a[N],b[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>w[i];
    a[0]=b[0]=1;
    for(int i=1;i<=n;++i){
        for(int j=m;j>=w[i];--j){
            a[j]+=a[j-w[i]];
            a[j]%=10;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(j-w[i]>=0)b[j]=(a[j]-b[j-w[i]]+10)%10;
            else b[j]=a[j]%10;
            cout<<b[j];
        }
        cout<<endl;
    }
    return 0;
}