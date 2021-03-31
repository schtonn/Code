#include "bits/stdc++.h"
using namespace std;
const int N=20010,inf=0x3f3f3f3f;
int n,k,a[N],b[N],w[N],ans;
int p[N],ng[N];//positive,negative
int main(){
    cin>>n>>k;
    memset(p,-inf,sizeof(p));
    memset(ng,-inf,sizeof(ng));
    p[0]=ng[0]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        w[i]=a[i]-b[i]*k;
        if(w[i]>=0){
            for(int j=N>>1;j>=w[i];j--){
                p[j]=max(p[j],p[j-w[i]]+a[i]);
            }
        }else{
            for(int j=N>>1;j>=-w[i];j--){
                ng[j]=max(ng[j],ng[j+w[i]]+a[i]);
            }
        }
    }
    for(int i=0;i<=N>>1;i++){
        ans=max(ans,p[i]+ng[i]);
    }
    if(ans)cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}