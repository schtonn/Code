#include "bits/stdc++.h"
using namespace std;
long long n,a,g,pos,neg;
int main(){
    cin>>n>>g;
    for(int i=2;i<=n;i++){
        cin>>a;
        pos+=max(0LL,a-g);
        neg+=max(0LL,g-a);
        g=a;
    }
    cout<<max(pos,neg)<<endl<<abs(pos-neg)+1<<endl;
    return 0;
}