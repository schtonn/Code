#include "bits/stdc++.h"
using namespace std;
const long long N=90,mod=10000000000;
long long m,n;
struct matrix{
    long long v[N+2][N+2];
    long long x,y;
}t,I,ans;
long long pre[N+2];
ostream&operator<<(ostream&ous,matrix a){
    for(long long i=0;i<a.x;i++){
        for(long long j=0;j<a.y;j++){
            ous<<a.v[i][j]%mod<<' ';
        }
        ous<<endl;
    }
    return ous;
}
matrix operator+(matrix a,matrix b){
    matrix c;
    if(a.x!=b.x||a.y!=b.y)return c;
    long long x=a.x,y=a.y;
    c.x=x;
    c.y=y;
    for(long long i=0;i<x;i++){
        for(long long j=0;j<y;j++){
            c.v[i][j]=(a.v[i][j]+b.v[i][j])%mod;
        }
    }
    return c;
}
matrix operator*(matrix a,matrix b){
    matrix c;
    if(a.y!=b.x)return c;
    long long x=a.x,y=b.y,z=a.y;
    c.x=x;
    c.y=y;
    for(long long i=0;i<x;i++){
        for(long long j=0;j<y;j++){
            c.v[i][j]=0;
            for(long long k=0;k<z;k++){
                c.v[i][j]=(c.v[i][j]+(a.v[i][k]*b.v[k][j]%mod))%mod;
            }
        }
    }
    return c;
}
void init(){
    t.x=t.y=2;
    I.x=I.y=2;
    t.v[0][0]=t.v[0][1]=t.v[1][0]=1;
    I.v[0][0]=I.v[1][1]=1;
}
int main(){
    cin>>m;
    init();
    long long cnt=m;
    ans=I;
    while(cnt){
        if(cnt&1)ans=ans*t;
        t=t*t;
        cnt>>=1;
    }
    cout<<ans.v[0][0]<<endl;
    return 0;
}