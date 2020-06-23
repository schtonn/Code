#include "bits/stdc++.h"
using namespace std;
int n,ans,d[100],p[100],f[100][100];
int main(){
	freopen("ValueHistogram.in","r",stdin);
	freopen("ValueHistogram.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=(i-1)*2;j++){
            if(f[i-1][j]!=-1){
                f[i][j+p[i-1]]=max(f[i][j+p[i-1]],f[i-1][j]+d[i-1]);
                if(f[i-1][j]>=d[i-1])f[i][j]=max(f[i][j],f[i-1][j]);
            }
        }
    }
    for(int i=n*2;i>=0;i--){
        if(f[n][i]!=-1)ans=i;
    }
    cout<<ans<<endl;
    return 0;
}