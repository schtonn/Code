#include "bits/stdc++.h"
using namespace std;
const long long N=1000010;
long long n,m,k,a[N],f[N][2],ans[N];
int main(){
    cin>>n>>k>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        ans[i]=i;
    }
    long long l=1,r=k+1;
    f[1][0]=r;
    for(long long i=2;i<=n;i++){
        while(r<n&&a[r+1]-a[i]<a[i]-a[l])l++,r++;
        f[i][0]=a[r]-a[i]>a[i]-a[l]?r:l;
    }
    for(long long i=0;(1LL<<i)<=m;i++){
        long long c=i&1;
        if(m&(1LL<<i)){
            for(long long j=0;j<=n;j++){
                ans[j]=f[ans[j]][c];
            }
        }
        for(long long j=1;j<=n;j++){
            f[ans[j]][!c]=f[f[ans[j]][c]][c];
        }
    }
    for(long long i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}