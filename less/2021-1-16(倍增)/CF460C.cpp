#include "bits/stdc++.h"
using namespace std;
const long long N=100010,inf=0x3f3f3f3f3f3f3f3f;
long long n,m,w,a[N],f[N<<1];
bool check(long long mid){
    long long tot=0,c=0;
    memset(f,0,sizeof(f));
    for(long long i=1;i<=n;i++){
        c+=f[i];
        if(a[i]+c<mid){
            long long num=mid-a[i]-c;
            tot+=num;
            f[i+w]=-num;
            c=mid-a[i];
        }
    }
    return tot<=m;
}
int main(){
    cin>>n>>m>>w;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long l=0,r=inf;
    while(l<=r){
        long long mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<l-1<<endl;
    return 0;
}