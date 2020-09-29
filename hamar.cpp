#include "bits/stdc++.h"
using namespace std;
int n,len,side,Tot,hj,i,t1,t2,a[5105],A[5105];

int main(){
    scanf("%d",&n);len=(n+20)/2;a[1]=2;side=1;Tot=0;hj=3;printf("3.");
    while(side&&++Tot<=200000000){
        for(t1=t2=0,i=len-1;i;i--){
            t1=a[i]*Tot+t2;
            a[i]=t1%100;
            t2=t1/100;
        }
        for(t2=0,i=0;i<len;i++){
            t1=a[i]+t2*100;
            a[i]=t1/hj;
            t2=t1%hj;
        }
        side=0;
        for(i=len-1;i;i--){
            A[i-1]+=(A[i]+a[i])/100;
            A[i]=(A[i]+a[i])%100;
            side|=(a[i]/10);
            side|=(a[i]%10);
        }
        hj+=2;
    }
    hj=0;
    for(i=2;i<=n+1;i++){
        hj+=2;
        if(hj>n){
            printf("%d",A[i]/10);
            break;
        }
        if(A[i]<10)printf("0");printf("%d",A[i]);
        if(hj==n)break;
    }
    return 0;
}