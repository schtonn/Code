#include "bits/stdc++.h"
using namespace std;
const int N=1<<5;
const int mod=10007;
int m,n;
int fact(int m) {
    if(m<2)return m;
    else{
        return fact(m/2)*10+m%2;
    }
}
bool T(int A,int B){
    if(A&B)return false;
    int C=A|B;
    int D=C^((1<<n)-1);
    int E=D/3;
    // cout<<fact(A)<<','<<fact(B)<<','<<fact(C)<<','<<fact(D)<<','<<fact(E);
    int F=E|(E<<1);
    if(F==D)return true;
    return false;
}
struct matrix{
    int v[N+2][N+2];
    int x,y;
}t,I,ans;
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
// void clear(matrix &a){
// 	for(int i=0;i<a.x;i++){
// 		for(int j=0;j<a.y;j++){
// 			if(i==j)a.v[i][j]=1;
// 			else a.v[i][j]=0;
// 		}
// 	}
// }
matrix operator+(matrix a,matrix b){
    matrix c;
    if(a.x!=b.x||a.y!=b.y)return c;
    int x=a.x,y=a.y;
    c.x=x;
    c.y=y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            c.v[i][j]=(a.v[i][j]+b.v[i][j])%mod;
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
                c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j]+mod)%mod;
            }
        }
    }
    return c;
}
void init(){
    t.x=t.y=1<<n;
    I.x=I.y=1<<n;
    pre[0]=1;
    for(int i=0;i<=(1<<n)-1;i++){
        for(int j=0;j<=(1<<n)-1;j++){
            if(i==j) I.v[i][j]=1;
            if(pre[i]||pre[j]){
                t.v[i][j]=T(i,j);
                if(t.v[i][j])pre[i]=pre[j]=1;
            }
            if(t.v[i][j])cout<<i<<"->"<<j<<endl;
            else cout<<i<<"  "<<j<<endl;
        }
    }
}
int main(){
    cin>>n>>m;
    init();
    int cnt=m;
    ans=I;
    while(cnt){
        if(cnt&1)ans=ans*t;
        t=t*t;
        cnt>>=1;
    }
    cout<<ans.v[0][0]%mod<<endl;
    // for(int i=1;i<=m;i++){//行数
    //     for(int cur=0;cur<=(1<<n)-1;cur++){//枚举本行状态(000~111)
    //         for(int pre=0;pre<=(1<<n)-1;pre++){//枚举上一行状态
    //             int k=T(pre,cur);
    //             F[i][cur]=(F[i][cur]+F[i-1][pre]*k)%mod;
    //         }
    //     }
    // }
    // cout<<F[m][0]<<endl;
    return 0;
}