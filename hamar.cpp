#include "bits/stdc++.h"
using namespace std;
string fAKe;
int n,num[100],fact,ans,tool=1;
int main(){
    cin>>fact>>fAKe;
    n=fAKe.length();
    for(int i=0;i<n;i++){
        if(fAKe[i]>='0'&&fAKe[i]<='9')num[i]=fAKe[i]-'0';
        if(fAKe[i]>='A'&&fAKe[i]<='Z')num[i]=fAKe[i]-'A'+10;
    }
    for(int i=n-1;i>=0;i--){
        cout<<ans<<endl;
        ans+=num[i]*tool;
        tool*=fact;
    }
    cout<<ans<<endl;
    return 0;
}