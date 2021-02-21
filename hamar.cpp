#include "bits/stdc++.h"
using namespace std;
int n,m,x,y,xcnt[10010],ycnt[10010],ans;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        xcnt[x]++;
        ycnt[y]++;
    }
    for(int i=1;i<=n;i++){
        ans+=max(0,xcnt[i]-2);
        ans+=max(0,ycnt[i]-2);
    }
    cout<<ans<<endl;
    return 0;
}