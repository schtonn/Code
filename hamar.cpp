#include "bits/stdc++.h"
using namespace std;
const long long N=90;
const long long mod=99999999;
long long n,tlen=7,initial[N+2]={6,5,1,4,2,3,1};
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
    {0,1,0,0,2,0,5},
    {1,0,0,0,3,2,3},
    {1,0,0,0,0,0,0},
    {0,1,0,0,0,0,0},
    {0,0,1,0,0,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,1},
};
ostream&operator<<(ostream&ous,matrix a){  
    for(long long i=0;i<a.x;i++){
        for(long long j=0;j<a.y;j++){
            ous<<a.v[i][j]<<' ';
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
    init();
    if(n==1){
        cout<<2<<endl<<3<<endl;
    }else if(n==2){
        cout<<1<<endl<<4<<endl;
    }else if(n==3){
        cout<<6<<endl<<5<<endl;
    }else{
        long long cnt=n-3;
        ans=I;
        while(cnt){
            if(cnt&1)ans=ans*t;
            t=t*t;
            cnt>>=1;
        }
        ans=ans*f;
        cout<<ans.v[0][0]<<endl<<ans.v[1][0]<<endl;
    }
    return 0;
}