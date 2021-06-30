#include "bits/stdc++.h"
using namespace std;
int a[7000010],b[7000010],c[7000010],ans[14000010];
int af,ar,bf,br,cf,cr;
int sumq=0;
int main(){
    int n,m,q,u,v,t;
    cin>>n>>m>>q>>u>>v>>t;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,greater<int>());
    ar=n;
    double p=(double)u/v;
    for(int i=1;i<=m;i++){
        int now;
        if(af<ar){
            if(a[af]>=max(b[bf],c[cf])){
                now=a[af];
                af++;
            }
            else if(b[bf]>=max(a[af],c[cf])){
                now=b[bf];
                bf++;
            }
            else{
                now=c[cf];
                cf++;
            }
        }
        else{
            if(b[bf]>c[cf]){
                now=b[bf];
                bf++;
            }
            else{
                now=c[cf];
                cf++;
            }
        }
        now+=sumq;
        sumq+=q;
        b[br]=(int)(p*now)-sumq;
        c[cr]=now-(int)(p*now)-sumq;
        br++;cr++;
        if(i%t==0)cout<<now<<' ';
    }
    cout<<endl;
    int cnt=1;
    for(int i=af;i<ar;i++)ans[cnt++]=a[i]+sumq;
    for(int i=bf;i<br;i++)ans[cnt++]=b[i]+sumq;
    for(int i=cf;i<cr;i++)ans[cnt++]=c[i]+sumq;
    sort(ans+1,ans+cnt,greater<int>());
    for(int i=t;i<cnt;i+=t){
        cout<<ans[i]<<' ';
    }
    return 0;
}