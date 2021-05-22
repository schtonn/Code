#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll len,l,s[110];
char ch[110];
const ll mod=123456789;
struct matrix{
    ll v[110][110];
    ll x,y;
}a,ans;
matrix operator*(matrix a,matrix b){
    matrix c;
    if(a.y!=b.x)return c;
    ll x=a.x,y=b.y,z=a.y;
    c.x=x;c.y=y;
    for(ll i=0;i<x;i++){
        for(ll j=0;j<y;j++){
            c.v[i][j]=0;
            for(ll k=0;k<z;k++){
                c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j]+mod)%mod;
            }
        }
    }
    return c;
}
ll pre(ll step,ll add){
    ll ans=0;
    for(ll i=1;i<=step;i++){
        ll flag=1;
        for(ll j=1;j<=i;j++){
            if(j==i){
                if(add!=s[j])flag=0;
            }else{
                if(s[step-i+j]!=s[j])flag=0;
            }
        }
        if(flag)ans=i;
    }
    return ans;
}
void init(){
    a.x=a.y=len;
    ans.x=1,ans.y=len;
    ans.v[0][0]=1;
    for(ll i=0;i<=len-1;i++){
        for(ll j=1;j<=4;j++){
            a.v[i][pre(i+1,j)]++;
        }
    }
}
ll qpow(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return ans%mod;
}
int main(){
    cin>>ch>>l;
    len=strlen(ch);
    for(ll i=0;i<len;i++){
        if(ch[i]=='A')s[i+1]=1;
        else if(ch[i]=='T')s[i+1]=2;
        else if(ch[i]=='G')s[i+1]=3;
        else if(ch[i]=='C')s[i+1]=4;
    }
    init();
    ll cnt=l;
    while(cnt){
        if(cnt&1)ans=ans*a;
        a=a*a;
        cnt>>=1;
    }
    ll sum=0;
    for(ll i=0;i<len;i++){
        sum=(sum+ans.v[0][i])%mod;
    }
    cout<<(qpow(4,l)-sum+mod)%mod<<endl;
    return 0;
}