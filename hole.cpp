#include "bits/stdc++.h"
#define ll long long
using namespace std;

const ll N=5000010;
const double pi=acos(-1);
string s;
ll n,m,p,c[N];
struct cpx{
    double real,imag;
    cpx(double X=0,double Y=0){real=X;imag=Y;}
}a[N],b[N];
inline cpx operator+(cpx a,cpx b){return cpx(a.real+b.real,a.imag+b.imag);}
inline cpx operator-(cpx a,cpx b){return cpx(a.real-b.real,a.imag-b.imag);}
inline cpx operator*(cpx a,cpx b){return cpx(a.real*b.real-a.imag*b.imag,a.real*b.imag+a.imag*b.real);}

void FFT(cpx*a,ll op){
    for(ll i=0;i<p;i++){
        if(i<c[i])swap(a[i],a[c[i]]);
    }
    for(ll i=1;i<p;i<<=1){
        cpx W(cos(pi/i),op*sin(pi/i));
        for(ll r=i<<1,j=0;j<p;j+=r){
            cpx w(1,0);
            for(ll l=0;l<i;l++,w=w*W){
                cpx x=a[j+l],y=w*a[j+i+l];
                a[j+l]=x+y;a[j+i+l]=x-y;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
//    while(true){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        freopen("ab.txt","w",stdout);
        freopen("a.txt","r",stdin);
        cin>>s;n=s.size()-1;
        for(ll i=0;i<=n;i++)a[n-i].real=s[i]-48;
        freopen("b.txt","r",stdin);
        cin>>s;m=s.size()-1;
        for(ll i=0;i<=m;i++)b[m-i].real=s[i]-48;
        p=1;ll l=0;
        while(p<=n+m){
            p<<=1;
            l++;
        }
        for(ll i=0;i<p;i++){
            c[i]=(c[i>>1]>>1)|((i&1)<<(l-1));
        }
        FFT(a,1);FFT(b,1);
        for(ll i=0;i<=p;i++){
            a[i]=a[i]*b[i];
        }
        FFT(a,-1);
        memset(c,0,sizeof(c));
        for(ll i=0;i<=n+m+1;i++){
            c[i]=a[i].real/p+0.5;
        }
        for(ll i=0;i<=n+m;i++){
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
        p=n+m+1;
        while(c[p]){
            c[p+1]+=c[p]/10;
            c[p]%=10;
            p++;
        }
        for(ll i=p-1;i>=0;i--){
            printf("%lld",c[i]);
        }
        printf("\n");
//    }
    return 0;
}