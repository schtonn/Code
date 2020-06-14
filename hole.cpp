#include "bits/stdc++.h"
using namespace std;
const int N=1<<10;
const int mod=10007;
int m,n,p;
int F[100][N];//F[i][j]表示骨牌覆盖完前i行，多余的骨牌状态为j的方案总数。
int hole[100];
int fact(int m) {
    if(m<2)return m;
    else{
        return fact(m/2)*10+m%2;
    }
}
bool T(int A,int B){
    int C=A|B;
    int D=C^((1<<n)-1);
    int E=D/3;
    cout<<fact(A)<<','<<fact(B)<<','<<fact(C)<<','<<fact(D)<<','<<fact(E);
    int F=E|(E<<1);
    if(A&B)return false;
    if(F==D)return true;
    return false;
}
int main(){
    freopen("Code\\f.test","w",stdout);
    cin>>n>>m>>p;
    int x,y;
    for(int i=1;i<=p;i++){
        cin>>x>>y;
        hole[y]|=1<<(x-1);
    }
    for(int i=1;i<=m;i++){
        cout<<fact(hole[i])<<endl;
    }
    if(m==2){
        F[0][hole[1]]=1;
    }else{
        F[0][0]=1;
    }
    for(int i=1;i<=m;i++){//行数
        for(int B=0;B<=(1<<n)-1;B++){//枚举本行状态
            for(int A=0;A<=(1<<n)-1;A++){//枚举上一行状态
                int k=T(A,B|hole[i]);
                F[i][B]=(F[i][B]+F[i-1][A]*k)%mod;
                cout<<","<<i<<","<<F[i][B]<<","<<F[i-1][A]<<","<<k<<endl;
            }
        }
    }
    cout<<F[m][0]<<endl;
    return 0;
}