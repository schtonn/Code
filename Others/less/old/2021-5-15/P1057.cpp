#include "bits/stdc++.h"
using namespace std;
const int N=90;
int k,n;
struct matrix{
    int v[N+2][N+2];
    int x,y;
}t,I,ans,base;
int pre[N+2];
ostream&operator<<(ostream&ous,matrix a){
    for(int i=0;i<a.x;i++){
        for(int j=0;j<a.y;j++){
            ous<<a.v[i][j]<<' ';
        }
        ous<<endl;
    }
    return ous;
}
matrix operator+(matrix a,matrix b){
    matrix c;
    if(a.x!=b.x||a.y!=b.y)return c;
    int x=a.x,y=a.y;
    c.x=x;
    c.y=y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            c.v[i][j]=(a.v[i][j]+b.v[i][j]);
        }
    }
    return c;
}
matrix operator*(matrix a,matrix b){
    matrix c;
    if(a.y!=b.x)return c;
    int x=a.x,y=b.y,z=a.y;
    c.x=x;
    c.y=y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            c.v[i][j]=0;
            for(int k=0;k<z;k++){
                c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j]);
            }
        }
    }
    return c;
}
void init(){
    t.x=t.y=n;
    I.x=I.y=n;
    base.x=n;
    base.y=1;
    base.v[0][0]=1;
    for(int i=0;i<n;i++)I.v[i][i]=1;
    for(int i=0;i<n;i++){
        t.v[(i-1+n)%n][i]=t.v[(i+1)%n][i]=1;
    }
}
int main(){
    cin>>n>>k;
    init();
    int cnt=k;
    ans=I;
    while(cnt){
        if(cnt&1)ans=ans*t;
        t=t*t;
        cnt>>=1;
    }
    cout<<(ans*base).v[0][0]<<endl;
    return 0;
}