#include "bits/stdc++.h"
using namespace std;
const long long N=90;
const long long mod=123456789;
long long n,tlen=4,initial[N+2]={1,1,1,1};
struct matrix{
    long long v[N+2][N+2];
    long long x,y;
    void clear(){
        for(long long i=0;i<N;i++){
            for(long long j=0;j<N;j++){
                v[i][j]=0;
            }
        }
    }
}t,I,ans,f;
long long base[N+2][N+2]={
    {1,1,0,0},
    {0,0,0,1},
    {1,1,0,0},
    {0,0,1,1},
};
ostream&operator<<(ostream&ous,matrix a){  
    for(long long i=0;i<a.x;i++){
        for(long long j=0;j<a.y;j++){
            ous<<a.v[j][i]%mod<<' ';
        }
        ous<<endl;
    }
    return ous;
}
matrix operator+(matrix a,matrix b){
    matrix c;
    c.clear();
    if(a.x!=b.x||a.y!=b.y){
        cout<<"error adding!"<<endl;
        return c;
    }
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
    c.clear();
    if(a.y!=b.x){
        cout<<"error multiplying!"<<endl;
        return c;
    }
    long long x=a.x,y=b.y,z=a.y;
    c.x=x;
    c.y=y;
    for(long long i=0;i<x;i++){
        for(long long j=0;j<y;j++){
            c.v[i][j]=0;
            for(long long k=0;k<z;k++){
                c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j])%mod;
            }
        }
    }
    return c;
}
void init(){
    t.x=t.y=tlen;
    I.x=I.y=tlen;
    f.x=tlen;
    f.y=1;
    for(long long i=0;i<tlen;i++){
        for(long long j=0;j<tlen;j++){
            t.v[i][j]=base[i][j];
        }
    }
    for(long long i=0;i<tlen;i++){
        f.v[i][0]=initial[i];
    }
    for(long long i=0;i<tlen;i++)I.v[i][i]=1;
}
int main(){
    cin>>n;
    if(n==1){
        cout<<2<<endl;
    }else if(n==2){
        cout<<4<<endl;
    }else{
        init();
        long long cnt=n-2;
        ans=I;
        while(cnt){
            if(cnt&1)ans=ans*t;
            t=t*t;
            cnt>>=1;
        }
        cout<<ans<<endl;
        ans=ans*f;
        long long kk=0;
        for(long long i=0;i<tlen;i++){
            kk+=ans.v[i][0];
        }
        cout<<kk%mod<<endl;
    }
    return 0;
}