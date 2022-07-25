#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9')c=getchar();
    while(c<='9' && c>='0')x=x*10+c-'0',c=getchar();
    return x*f;
}
const ll m1=11;
const ll m2=m1*2+2;
const ll m3=m2;
ll n;
struct Matrix{
    ll a[3][3];
    Matrix(){memset(a,0,sizeof a);}
    Matrix operator+(const Matrix & p)const{
        Matrix ret;
        for(ll i=0;i<=1;++i)
            for(ll j=0;j<=1;++j)
                for(ll k=0;k<=1;++k)
                    ret.a[i][j]=(ret.a[i][j]+a[i][k]*p.a[k][j])%m1;
        return ret;
    }
};
ll get1(ll x){
    Matrix p,q;
    p.a[0][0]=1;p.a[0][1]=1;p.a[1][0]=1;
    q.a[0][1]=1;//,q.a[1][1]=1;
    for(;x;x>>=1,p=p+p)
        if(x & 1)q=q+p;
    return q.a[0][0];
}
char s[1000007];
struct bign{
    ll z[1000007],l;
    void init(){
        memset(z,0,sizeof(z));
        cin>>s+1;
        l=strlen(s+1);
        for(ll i=1;i<=l;i++)
            z[i]=s[l-i+1]-'0';
    }
    ll operator %(const long long & a)const{
        ll b=0;
        for(ll i=l;i>=1;i--)
            b=(b*10+z[i])% a;
        return b;
    }
}z;
int main(){
    ll t=read();
    bign num;
    while(t--){
        num.init();
        n=num%10000;
//		n=num%m3;
        printf("%lld\n",get1(n));
    }
    return 0;
}
/*
https://zhuanlan.zhihu.com/p/166123245
http://t.zoukankan.com/sssy-p-9418732.html
*/