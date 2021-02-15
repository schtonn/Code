#include "bits/stdc++.h"
using namespace std;
int n;
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int g=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}
int main(){
    int a,b,c,x=0,y=0,g;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        g=exgcd(a,b,x,y);
        if(c%g){
            cout<<"no solution"<<endl;
            continue;
        }
        int w=c/g;
        x*=w;
        y*=w;
        a/=g;
        b/=g;
        if(x>0){
            int t=x/b;
            x-=t*b;
            y+=t*a;
        }
        while(x<=0){
            x+=b;
            y-=a;
        }
        cout<<x<<' '<<y<<endl;
    }
    return 0;
}