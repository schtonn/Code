#include "bits/stdc++.h"
using namespace std;
const long long N=1000010;
long long m,n,k,p;
struct matrix{
    long long v[5][5];
    long long x,y;
}f,A,B,I,ans;
long long e[N],g[N];
void geteg(long long u){
    long long a=u,b=u*2%k,a1=u,b1=u*2%k,st=1;
    while(b!=1){
        swap(a1,b1);
        b1=(a1+b1)%k;
        st++;
        if((a==a1&&b==b1)||(a==b&&e[a]==-1)){
            st=a=-1;
            break;
        }
        if(a==b&&e[a]){
            st+=e[a]-1;
            a=g[a];
            break;
        }
        // cout<<"("<<a<<' '<<a1<<","<<b<<' '<<b1<<")->";
        swap(a,b);
        b=(a+b)%k;
        swap(a1,b1);
        b1=(a1+b1)%k;
    }
    e[u]=st;
    g[u]=a;
}
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
    if(a.x!=b.x||a.y!=b.y)return c;
    long long x=a.x,y=a.y;
    c.x=x;
    c.y=y;
    for(long long i=0;i<x;i++){
        for(long long j=0;j<y;j++){
            c.v[i][j]=(a.v[i][j]+b.v[i][j])%p;
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
                c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j])%p;
            }
        }
    }
    return c;
}
matrix operator^(matrix a,long long b){
    matrix c=I;
    while(b){
        if(b&1)c=c*a;
        a=a*a;
        b>>=1;
    }
    return c;
}
void init(){
    A.x=A.y=B.x=B.y=3;
    I.x=I.y=3;
    f.x=3;f.y=1;
    f.v[1][0]=f.v[2][0]=1;
    A.v[0][0]=A.v[0][1]=A.v[1][0]=A.v[2][2]=1;
    B.v[0][0]=B.v[0][1]=B.v[1][0]=B.v[2][2]=1;
    B.v[0][2]=-1;
    I.v[0][0]=I.v[1][1]=I.v[2][2]=1;
}
int main(){
    // freopen("rabbit.in","r",stdin);
    // freopen("rabbit.out","w",stdout);
    init();
    cin>>n>>k>>p;
    for(long long i=1;i<k;i++){
        geteg(i);
        if(e[i]==-1)cout<<"N";
        else cout<<"Y";
    }
    long long cur=1,ptr=0;
    while(true){
        if(ptr+e[cur]+1>n||e[cur]==-1){
            f=(A^(n-ptr))*f;
            break;
        }
        // cout<<"a\n"<<f;
        f=(A^(e[cur]+1))*f;
        // cout<<"b\n"<<f;
        ptr+=e[cur]+1;
        if(ptr>=n)break;
        f=B*f;
        // cout<<"c\n"<<f;
        ptr++;
        cur=g[cur];
        if(ptr>=n)break;
    }
    cout<<f.v[0][0]<<endl;
    return 0;
}