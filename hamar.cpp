#include "bits/stdc++.h"
using namespace std;
int n,m,k,ans,f[110];
int main(){
    // freopen("PiecewiseLinearFunctionDiv2.in","r",stdin);
    // freopen("PiecewiseLinearFunctionDiv2.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>k;
        ans=0;
        for(int j=0;j<n-1;j++){
            if(f[j]==k||(f[j]<k&&f[j+1]>k)||(f[j]>k&&f[j+1]<k))ans++;
            if(f[j]==k&&f[j+1]==k){
                ans=-1;
                break;
            }
        }
        if(f[n-1]==k&&ans!=-1)ans++;
        cout<<ans<<' ';
    }
    return 0;
}