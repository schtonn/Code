#include "bits/stdc++.h"
using namespace std;
int n,f[1010][1010],a[10010],b[10010],d[10010],t[10010],buf[10010];
void solve(){
    memset(f,0,sizeof(f));
    memset(t,0,sizeof(t));
    cin>>n;
    int cnt=0;
    cnt=n*2;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>d[i];
        buf[i*2-1]=a[i];
        buf[i*2]=b[i];
    }
    sort(buf+1,buf+cnt+1);
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(buf+1,buf+cnt+1,a[i])-buf;
        b[i]=lower_bound(buf+1,buf+cnt+1,b[i])-buf;
    }
    for(int p=1;p<=cnt;p++){
        for(int i=1;i+p-1<=cnt;i++){
            int j=i+p-1,id=-1;
            for(int k=1;k<=n;k++){
                if(i<=a[k]&&b[k]<=j&&(id==-1||d[id]<d[k])){
                    id=k;
                }
            }
            if(id==-1){
                f[i][j]=0;
                continue;
            }
            f[i][j]=0x3f3f3f3f;
            for(int k=a[id];k<=b[id];k++){
                f[i][j]=min(f[i][j],f[i][k-1]+f[k+1][j]+d[id]);
            }
        }
    }
    cout<<f[1][cnt]<<endl;
}
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        solve();
    }
    return 0;
}