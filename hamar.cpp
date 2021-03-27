#include "bits/stdc++.h"
using namespace std;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int g=gcd(gcd(a,b),c);
        a/=g;
        b/=g;
        c/=g;
        if(a>b)swap(a,b);
        if(b>c)swap(b,c); 
        if(a>b)swap(a,b);
        if(a==0&&b==0){
            cout<<0<<endl;
            continue;
        }
        if(a==0){
            if(b==c)cout<<1<<endl;
            else cout<<2<<endl;
            continue;
        }
        if(a+b==c||a==b||b==c){
            cout<<2<<endl;
            continue;
        }
        cout<<3<<endl;
    }
    return 0;
}
/*
6
0 0 8
0 5 3
9 9 0
6 2 4
1 7 4
5 8 5
*/