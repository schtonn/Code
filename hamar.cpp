#include "bits/stdc++.h"
using namespace std;
#define MAXN 1000
const long long mod=1e9+9;
long long C[MAXN+10][MAXN+10],l;
long long fact(long long n){
    long long ans=1;
    for(long long i=26;i>26-n;i--){
        ans=(ans*i)%mod;
    }
    return ans%mod;
}
long long P(long long n,long long m){
    long long ans=1;
    for(long long i=0;i<m;i++){
        ans=(ans*n)%mod;
        n--;
    }
    return ans;
}
int main(){
    // C[0][0]=1;
    // for(long long i=1;i<MAXN;i++){
    //     C[i][0]=C[i][i]=1;
    //     for(long long j=1;j<=i;j++){
    //         C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    //     }
    // }
    cin>>l;
    if(l<=26)cout<<P(26,l)<<endl;
    else cout<<(P(l-1,25)*26)%mod<<endl;
    return 0;
}