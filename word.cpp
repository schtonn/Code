#include "bits/stdc++.h"
using namespace std;
int main(){
    int t,l,r,k,g;
    cin>>t;
    for(int p=1;p<=t;p++){
        cin>>l>>r>>k;
        int ans=0;
        g=r-l;
        for(int i=k;i>=2;i--){
            if(i==2)ans+=g;
            else {
                g=max(1,(int)sqrt(g)-2);
                ans+=g;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}