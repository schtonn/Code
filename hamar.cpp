#include "bits/stdc++.h"
using namespace std;
long long n,rad[110],per[110];
double dis[110],ans=0x3f3f3f3f3f3f3f3f;
int main(){
    // freopen("MarblePositioning.in","r",stdin);
    // freopen("MarblePositioning.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>rad[i];
        per[i]=i;
    }
    do{
        dis[1]=0;
        for(long long i=2;i<=n;i++){
            dis[i]=0;
            for(long long j=1;j<i;j++){
                long long a=rad[per[i]],b=rad[per[j]];
                dis[i]=max(dis[i],dis[j]+sqrt((a+b)*(a+b)-(a-b)*(a-b)));
            }
        }
        ans=min(ans,dis[n]);
    }while(next_permutation(per+1,per+1+n));
    printf("%.30lf",ans);
    return 0;
}