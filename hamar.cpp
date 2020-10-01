#include "bits/stdc++.h"
using namespace std;
int a,b,a1,b1,l;
int gcd(int a,int b){
    if(!b)return a;
    else return gcd(b,a%b);
}
int main(){
    cin>>a>>b>>l;
    a1=l;b1=1;
    for(int i=1;i<=l;i++){
        for(int j=1;j<=l;j++){
            if(gcd(i,j)==1&&i*b>=j*a&&i*b1<j*a1){
                a1=i;
                b1=j;
            }
        }
    }
    cout<<a1<<' '<<b1<<endl;
    return 0;
}