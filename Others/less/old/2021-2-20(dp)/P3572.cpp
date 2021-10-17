#include "bits/stdc++.h"
using namespace std;
const int N=1000010;
int n,q,k,s,t,a[N],g[N],f[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>q;
    while(q--){
        cin>>k;
        s=t=1;
        g[t]=1;
        for(int i=2;i<=n;i++){
            while(s<=t&&i-g[s]>k)s++;
            if(a[g[s]]>a[i])f[i]=f[g[s]];
            else f[i]=f[g[s]]+1;
            while(s<=t&&(f[g[t]]>f[i]||(f[g[t]]==f[i]&&a[g[t]]<=a[i])))t--;
            g[++t]=i;
        }
        cout<<f[n]<<endl;
    }
    return 0;
}