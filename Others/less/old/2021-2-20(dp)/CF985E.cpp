#include "bits/stdc++.h"
using namespace std;
int n,k,d,a[500010];
bool f[500010];
int main(){
    cin>>n>>k>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);f[0]=true;
    int p=1;
    for(int i=0;i<=n;i++){
        if(f[i]){
            p=max(p,i+k);
            while(p<=n&&a[i+1]+d>=a[p])f[p++]=true;
        }
    }
    if(f[n])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}