#include "bits/stdc++.h"
using namespace std;
int n,v,a[100];
bitset<20010>f,one;
int main(){
    cin>>v>>n;
    f[0]=1;
    for(int i=0;i<=v;i++)one[i]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f=(f|(f<<a[i]))&one;
    }
    for(int i=v;i>=0;i--){
        if(f[i]){
            cout<<v-i<<endl;
            return 0;
        }
    }
    return 0;
}