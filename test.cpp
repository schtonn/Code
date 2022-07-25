#include "bits/stdc++.h"
using namespace std;
const int N=100010;
int n,a[N],ls[N],rs[N];
void build(int l,int r,int gl,int gr){
    int p=l+(a[l]-gl);
    cout<<l<<' '<<r<<' '<<p<<' '<<gl<<' '<<gr<<endl;
    if(gl<a[l]-1){
        ls[l]=l+1;
        build(ls[l],p,gl,a[l]-1);
    }
    if(gr>a[l]){
        rs[l]=p+1;
        build(rs[l],r,a[l]+1,gr);
    }
}
void print(int p){
    if(p==0)return;
    print(ls[p]);
    cout<<a[p]<<' ';
    print(rs[p]);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,n,1,n);
    for(int i=1;i<=n;i++){
        cout<<ls[i]<<' '<<rs[i]<<endl;
    }
    print(1);
    return 0;
}