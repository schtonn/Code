#include "bits/stdc++.h"
using namespace std;
void exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y=y-a/b*x;
}
int main(){
    int a,b,x,y;
    cin>>a>>b;
    exgcd(a,b,x,y);
    cout<<(x+b)%b<<endl;
    return 0;
}