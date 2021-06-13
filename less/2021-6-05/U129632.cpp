#include "bits/stdc++.h"
using namespace std;
int n,t,l,r,x;
bitset<100010>f,g,one;
int main(){
    cin>>n>>t>>l>>r>>x;
    r-=l;
    x-=l;
    f[x]=1;
    for(int i=0;i<=r;i++)one[i]=1;
    int p=0,a;
    for(int i=1;i<=n;i++){
        cin>>a;
        f=((f<<(a-p))|(f>>(a-p)))&one;
        p=a;
    }
    f=((f<<(t-a))|(f>>(t-a)))&one;
    for(int i=r;i>=0;i--){
        if(f[i]){
            cout<<t-(i-(x-t))/2<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}