#include "bits/stdc++.h"
using namespace std;
const long long N=100010,K=50;
long long n,k,son[N][K],mis[N][K],mi[N][K];
long long getMis(long long c,long long x){
    if(!x)return x;
    long long p=0,dp=1;
    while(dp<=x){
        p++;
        dp<<=1;
    }
    p--;dp>>=1;
    return mis[c][p]+getMis(son[c][p],x-dp);
}
long long getMi(long long c,long long x){
    if(!x)return 0x3f3f3f3f;
    long long p=0,dp=1;
    while(dp<=x){
        p++;
        dp<<=1;
    }
    p--;dp>>=1;
    return min(mi[c][p],getMi(son[c][p],x-dp));
}
int main(){
    cin>>n>>k;
    for(long long i=0;i<n;i++)cin>>son[i][0];
    for(long long i=0;i<n;i++){
        cin>>mis[i][0];
        mi[i][0]=mis[i][0];
    }
    for(long long p=1;p<K;p++){
        for(long long i=0;i<n;i++){
            son[i][p]=son[son[i][p-1]][p-1];
        }
    }
    for(long long p=1;p<K;p++){
        for(long long i=0;i<n;i++){
            mi[i][p]=min(mi[i][p-1],mi[son[i][p-1]][p-1]);
            mis[i][p]=mis[i][p-1]+mis[son[i][p-1]][p-1];
        }
    }
    for(long long i=0;i<n;i++){
        cout<<getMis(i,k)<<' '<<getMi(i,k)<<endl;
    }
    return 0;
}