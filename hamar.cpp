#include "bits/stdc++.h"
using namespace std;
const int N=200010; 
int n,x[N],c[N],s[N],ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>c[i]>>s[i];
    for(int i=1;i<=n;i++){
        ans+=c[i];
        int j=i;
        while(x[i]+s[i]<=x[j])j++;
        i=j;
    }
    cout<<ans<<endl;
    return 0;
}