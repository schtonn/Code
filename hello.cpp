#include "bits/stdc++.h"
using namespace std;
char s[100010];
int main(){
    long long n,t;
    cin>>n>>t>>s;
    long long len=n;
    for(long long i=0;i<n&&s[i]=='0';i++)len--;
    long long c=1;
    while(c<len)c<<=1;
    t%=c;
    for(int j=1;j<=t;j++){
        for(int i=n-1;i>=1;i--){
            s[i]=(s[i]^s[i-1])?'1':'0';
        }
    }
    cout<<s;
    return 0;
}