#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
    return x*f;
}
ll p,p2;
ll n;
struct Matrix{
    ll a[3][3];
    Matrix(){memset(a,0,sizeof a);}
    Matrix operator+(const Matrix&b)const{
        Matrix ret;
        for(ll i=0;i<=1;++i)
            for(ll j=0;j<=1;++j)
                for(ll k=0;k<=1;++k)
                    ret.a[i][j]=(ret.a[i][j]+(a[i][k]*b.a[k][j])%p)%p;
        return ret;
    }
};
ll get1(ll x){
    Matrix P,Q;
    P.a[0][0]=1;P.a[0][1]=1;P.a[1][0]=1;
    Q.a[0][1]=1;
    for(;x;x>>=1,P=P+P)if(x&1)Q=Q+P;
    return Q.a[0][0];
}
char s[10000007];
int z[10000007];
ll l;


void init(){
    memset(z,0,sizeof(z));
    scanf("%s",s+1);
    l=strlen(s+1);
    for(ll i=1;i<=l;i++)
        z[i]=s[l-i+1]-'0';
}
ll qpow(ll a,ll b,ll p){
    ll ret=1;
    for(;b;b>>=1){
        if(b&1)ret=(ret*a)%p;
        a=(a*a)%p;
    }
    return ret;
}

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}

ll g(ll p){
    if(p==2)return 3;
    if(p==3)return 8;
    if(p==5)return 20;
    if(qpow(5,(p-1)/2,p)==1)return p-1;
    return p*2+2;
}

void calc(ll p,ll k){
    p2=lcm(p2,g(p)*qpow(p,k-1,LLONG_MAX-1));
}

void divide(ll n){
    for(ll i=2;i<=n/i;i++){
        if(n%i==0){
            ll s=0;
            while(n%i==0){
                n/=i;
                s++;
            }
            calc(i,s);
        }
    }
    if(n>1)calc(n,1);
}

int main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    // ll t=5000;
    init();
    p=read();
    p2=1;
    divide(p);
    // cout<<p2<<endl;
    // while(t--){
        // n=p2+4900-t;
        n=0;
        for(ll i=l;i>=1;i--)n=(n*10+z[i])%p2;
        printf("%lld\n",get1(n));
    // }
    return 0;
}
/*
*/