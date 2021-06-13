#include "bits/stdc++.h"
using namespace std;
int a[5010],f[5010][4];
int n,ans=-1;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i]){
                f[i][0]=max(f[i][0],f[j][0]+1);
                f[i][1]=max(f[i][1],f[j][0]+1);
                f[i][2]=max(f[i][2],f[j][2]+1);
                f[i][3]=max(f[i][3],f[j][2]+1);
            }else if(a[j]>a[i]){
                f[i][1]=max(f[i][1],f[j][1]+1);
                f[i][2]=max(f[i][2],f[j][1]+1);
                f[i][3]=max(f[i][3],f[j][3]+1);
            }
        }
    }
    for(int i=1;i<=n;i++)ans=max(ans,f[i][3]);
    cout<<ans<<endl;
    return 0;
}