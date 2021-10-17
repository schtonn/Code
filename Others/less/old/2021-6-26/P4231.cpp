#include "bits/stdc++.h"
const int N=10000010;
using namespace std;
int n,m,l,r,s,e,p;
long long a[N],s1[N],s2[N],mx,ans;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s1[i]=a[i]-a[i-1];
        s2[i]=s1[i]-s1[i-1];
    }
    for(int i=1;i<=m;i++){
        cin>>l>>r>>s>>e;
        p=(e-s)/(r-l);
        s2[l]+=s;
        s2[l+1]+=p-s;
        s2[r+1]+=-p-e;
        s2[r+2]+=e;
    }
    for(int i=1;i<=n;i++){
        s1[i]=s1[i-1]+s2[i];
        a[i]=a[i-1]+s1[i];
        mx=max(mx,a[i]);
        ans^=a[i];
    }
    cout<<ans<<' '<<mx<<endl;
    return 0;
}