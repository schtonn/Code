#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll t,l,r;
int main(){
    cin>>t;
    while(t--){
        cin>>l>>r;
        l%=9;
        r%=9;
        cout<<(((l+r)*(r-l+1))/2+81)%9<<endl;
    }
    return 0;
}