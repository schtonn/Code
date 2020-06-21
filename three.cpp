#include "bits/stdc++.h"
using namespace std;
const int N=1<<10;
const int mod=10007;
int m,n;
int F[100][N];//F[i][j]表示骨牌覆盖完前i行，多余的骨牌状态为j的方案总数。
int fact(int m) {
    if(m<2)return m;
    else{
        return fact(m/2)*10+m%2;
    }
}
bool T(int A,int B,int C){
    if((A&B)||(B&C)||(C&A))return false;
    int D=A|B|C;
    int E=D^((1<<n)-1);
    int F=E/7;
    // cout<<fact(A)<<','<<fact(B)<<','<<fact(C)<<','<<fact(D)<<','<<fact(E);
    int G=F|(F<<1);
    if(G==E)return true;
    return false;
}
bool T2(int A,int B){
    if(A&B)return false;
    int C=A|B;
    int D=C^((1<<n)-1);
    int E=D/7;
    int F=E|(E<<1);
    if(F==D)return true;
    return false;
}
int main(){
    cin>>n>>m;
    F[0][0]=1;
    for(int cur=0;cur<=(1<<n)-1;cur++){//枚举本行状态(000~111)
        for(int pre=0;pre<=(1<<n)-1;pre++){//枚举上一行状态
            int k=T2(pre,cur);
            F[1][cur]=(F[1][cur]+F[0][pre]*k)%mod;
        }
    }
    for(int i=2;i<=m;i++){//行数
        for(int cur=0;cur<=(1<<n)-1;cur++){//枚举本行状态(000~111)
            for(int pre=0;pre<=(1<<n)-1;pre++){//枚举上一行状态
                for(int ppre=0;ppre<=(1<<n)-1;ppre++){
                    int k=T(ppre,pre,cur);
                    F[i][cur]=(F[i][cur]+F[i-2][ppre]*k)%mod;
                    if(k)cout<<i<<","<<cur<<","<<F[i][cur]<<","<<pre<<","<<F[i-1][pre]<<","<<ppre<<","<<F[i-2][ppre]<<","<<k<<endl;
                }
            }
        }
    }
    cout<<F[m][0]<<endl;
    return 0;
}