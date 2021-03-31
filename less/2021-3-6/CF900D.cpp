#include "bits/stdc++.h"
using namespace std;
const int mod=1e9+7;
std::map<int,int>mp;
int qpow(int a,int n){
    int ans=1;
    while(n){
        if(n&1)ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        n>>=1;
    }
    return ans%mod;
}
void upd(int&x,int y){
    (x+=y)>=mod&&(x-=mod);
}
int solve(int n){
    if(n==1)return 1;
    if(mp.count(n))return mp[n];
    int ans=0;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            upd(ans,solve(i));
            if(i*i!=n)upd(ans,solve(n/i));
        }
    }
    upd(ans,solve(1));
    ans=(qpow(2,n-1)-ans+mod)%mod;
    return mp[n]=ans;
}
int main(){
    int x,y;
    cin>>x>>y;
    if(y%x)cout<<0<<endl;
    else cout<<solve(y/x)<<endl;
    return 0;
}