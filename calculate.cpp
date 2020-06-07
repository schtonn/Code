#include "bits/stdc++.h"
using namespace std;
const int N=1<<10;
int n=3,m;
int F[N][25];//F[i][B]表示骨牌覆盖完前i行，多余的骨牌状态为j的方案总数。
int fact(int n) {
    if(n<2)return n;
    else{
        return fact(n/2)*10+n%2;
    }
}
bool T(int A,int B){
    int C=A|B;
    int D=C^((1<<m)-1);
    int E=D/3;
    int F=E|(E<<1);
    cout<<fact(A)<<",B="<<fact(B)<<",C="<<fact(C)<<",D="<<fact(D)<<",E="<<fact(E)<<",F="<<fact(F);
    if(A&B)return false;
    if(F==D)return true;
    return false;
}
int main(){
    int A,B;
    cin>>m>>A>>B;
    cout<<T(A,B)<<endl;
    return 0;
}