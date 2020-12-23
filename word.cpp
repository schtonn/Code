#include "bits/stdc++.h"
using namespace std;
int n,k,len;
string s;
int main(){
    // freopen("word.in","r",stdin);
    // freopen("word.out","w",stdout);
    cin>>n>>k;
    cin>>s;
    cout<<s;
    len+=s.length();
    for(int i=1;i<n;i++){
        cin>>s;
        if(len+s.length()<=k){
            cout<<' ';
            cout<<s;
            len+=s.length();
        }else{
            cout<<endl<<s;
            len=s.length();
        }
    }
    system("pause");
    return 0;
}