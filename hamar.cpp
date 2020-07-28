#include "bits/stdc++.h"
using namespace std;
int n,fact,out[100],cnt;
int main(){
    cin>>n>>fact;
    while(n){
        out[cnt++]=n%fact;
        n/=fact;
    }
    for(int i=cnt-1;i>=0;i--){
        cout<<out[i];
    }
    return 0;
}