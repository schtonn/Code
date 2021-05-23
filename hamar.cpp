#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll n;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll g=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}
int main(){
    freopen("file2.out","w",stdout);
    ll a,b,c,x=0,y=0,g;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a>>b>>c;
        g=exgcd(a,b,x,y);
        if(c%g){
            cout<<"no solution"<<endl;
            continue;
        }
        ll w=c/g;
        x*=w;
        y*=w;
        a/=g;
        b/=g;
        if(x>0){
            ll t=x/b;
            x-=t*b;
            y+=t*a;
        }
        if(x<0){
            ll t=(-x)/b;
            x+=t*b;
            y-=t*a;
        }
        while(x<0){
            x+=b;
            y-=a;
        }
        cout<<x<<' '<<y<<endl;
    }
    return 0;
}