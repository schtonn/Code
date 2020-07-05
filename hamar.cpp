#include<iostream>
#include<algorithm>
using namespace std;
int r[55],g[55],b[55],n,T[55],ans=int(1e9);
bool Tr=0,Tg=0,Tb=0;
int main()
{
    freopen("minOperations.in","r",stdin);
    freopen("minOperations.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>r[i];
    for(int i=1;i<=n;i++)cin>>g[i];
    for(int i=1;i<=n;i++)cin>>b[i];



    for(int i=1;i<=n;i++){
        Tr|=r[i];
        Tg|=g[i];
        Tb|=b[i];
        if(r[i]>=g[i]&&r[i]>=b[i])T[i]=g[i]+b[i];
        else if(g[i]>=r[i]&&g[i]>=b[i])T[i]=r[i]+b[i];
        else if(b[i]>=r[i]&&b[i]>=g[i])T[i]=r[i]+g[i];
    }
    if(Tr+Tg+Tb>n){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            for(int k=1;k<=n;k++){
                if(i==k||j==k)continue;
                int s=0;
                for(int l=1;l<=n;l++){
                    if(l==i&&Tr)s+=g[l]+b[l];
                    else if(l==j&&Tg)s+=r[l]+b[l];
                    else if(l==k&&Tb)s+=r[l]+g[l];
                    else s+=T[l];
                }
                ans=min(ans,s);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}