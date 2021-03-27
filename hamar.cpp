#include "bits/stdc++.h"
using namespace std;
const int N=100010;
int n,q,a[N],b[N];
int main(){
    ios::sync_with_stdio(false);
    freopen("island.in","r",stdin);
    freopen("island.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(register int i=1;i<=q;i++){
        int l,r,c,d;
        cin>>l>>r>>c>>d;
        int ans=0;
        for(register int i=l;i<=r;i++){
            if((a[i]^c)<=min(b[i],d))ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}