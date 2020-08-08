#include "bits/stdc++.h"
using namespace std;
int n,ans;
int main(){
    // freopen("SemiPerfectSquare.in","r",stdin);
    // freopen("SemiPerfectSquare.out","w",stdout);
    cin>>n;
    for(int i=2;i<35;i++){
        for(int j=1;j<i;j++){
            if(i*i*j==n){
                ans=1;
            }
        }
    }
    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}