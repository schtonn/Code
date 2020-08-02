#include "bits/stdc++.h"
using namespace std;
int n,rad[110],per[110];
double dis[110],ans=0x3f3f3f3f;
int main(){
	// freopen("MarblePositioning.in","r",stdin);
	// freopen("MarblePositioning.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>rad[i];
        per[i]=i;
    }
    do{
        dis[1]=0;
        for(int i=2;i<=n;i++){
            dis[i]=0;
            for(int j=1;j<i;j++){
                int a=rad[per[i]],b=rad[per[j]];
                dis[i]=max(dis[i],dis[j]+sqrt((a+b)*(a+b)-(a-b)*(a-b)));
            }
        }
        ans=min(ans,dis[n]);
    }while(next_permutation(per+1,per+1+n));
    cout<<ans<<endl;
    return 0;
}