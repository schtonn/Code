#include "bits/stdc++.h"
using namespace std;
int n,ans,a[100];
int main(){
    // freopen("LISNumberDivTwo.in","r",stdin);
    // freopen("LISNumberDivTwo.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0&&a[i]>a[i-1]){
            ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}