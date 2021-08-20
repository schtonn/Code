#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll N=90,mod=998244353;
struct matrix{
    ll v[N+2][N+2];
    ll x,y;
}t[N];
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll qpow(ll x,ll a){
    x%=mod;
    ll ans=1;
    while(a){
        if(a&1)ans=(ans*x)%mod;
        x=(x*x)%mod;
        a>>=1;
    }
    return ans%mod;
}
ostream&operator<<(ostream&ous,matrix a){
    for(ll i=0;i<a.x;i++){
        for(ll j=0;j<a.y;j++){
            ous<<a.v[i][j]<<' ';
        }
        ous<<endl;
    }
    return ous;
}
matrix operator+(matrix a,matrix b){
    matrix c;
    if(a.x!=b.x||a.y!=b.y)return c;
    ll x=a.x,y=a.y;
    c.x=x;
    c.y=y;
    for(ll i=0;i<x;i++){
        for(ll j=0;j<y;j++){
            c.v[i][j]=(a.v[i][j]+b.v[i][j])%mod;
        }
    }
    return c;
}
matrix operator*(matrix a,matrix b){
    matrix c;
    if(a.y!=b.x)return c;
    ll x=a.x,y=b.y,z=a.y;
    c.x=x;
    c.y=y;
    for(ll i=0;i<x;i++){
        for(ll j=0;j<y;j++){
            c.v[i][j]=0;
            for(ll k=0;k<z;k++){
                c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j])%mod;
            }
        }
    }
    return c;
}
ll T,k,n[N],m[N];
void init(){
    for(ll i=1;i<k;i++){
        t[i].x=n[i+1];
        t[i].y=n[i];
    }
}
matrix getI(ll x){
    matrix ret;
    ret.x=ret.y=x;
    for(ll i=0;i<x;i++){
        ret.v[i][i]=1;
    }
    return ret;
}
ll det(matrix a){
    ll ret=1,c=1,n=a.x,neg=1;
    if(a.x!=a.y)return 0;
    for(ll g=0,h=0;g<n&&h<n;g++,h++){
        ll flag=g;
        for(ll i=g;i<n;i++){
            if(a.v[i][h]){flag=i;break;}
        }
        if(!a.v[flag][h]){g--;continue;}
        if(flag!=g){
            ret*=-1;
            for(ll i=h;i<n;i++){
                swap(a.v[g][i],a.v[flag][i]);
            }
        }
        for(ll i=g+1;i<n;i++){
            if(a.v[i][h]){
                ll t1=gcd(abs(a.v[i][h]),abs(a.v[g][h]));
                ll t2=a.v[g][h]/t1;
                t1=a.v[i][h]/t1;
                if(t2<0)neg*=-1;
                c=(c*abs(t2))%mod;
                for(ll j=h;j<n;j++){
                    a.v[i][j]=(((a.v[i][j]*t2)%mod)-((a.v[g][j]*t1)%mod))%mod;
                }
            }
        }
        cout<<a<<endl;
    }
    for(ll i=1;i<a.x;i++){
        ret=(ret*a.v[i][i])%mod;
    }
    cout<<ret<<' '<<c<<endl;
    return neg*(ret*(qpow(c,mod-2)%mod))%mod;
}
int pre[4][4]={
    {1,6,5,4},
    {7,2,3,11},
    {8,9,10,12},
    {16,15,14,13}
};
// int pre[4][4]={
//     {1,6,5,4},
//     {7,2,3,11},
//     {8,9,10,12},
//     {16,15,14,13}
// };
int main(){
    cin>>T;
    while(T--){
        cin>>k;
        for(ll i=1;i<=k;i++)cin>>n[i];
        init();
        for(ll i=1;i<k;i++)cin>>m[i];
        matrix f=getI(n[1]);
        for(ll i=1;i<k;i++){
            for(ll j=1;j<=m[i];j++){
                ll u,v;
                cin>>u>>v;
                t[i].v[v-1][u-1]=1;
            }
            f=t[i]*f;
            cout<<f<<endl;
        }
        cout<<det(f)<<"GGG"<<endl;
    }
    matrix y;
    y.x=y.y=4;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            y.v[i][j]=pre[i][j];
        }
    }
    cout<<y<<endl;
    cout<<det(y)<<endl;
    return 0;
}