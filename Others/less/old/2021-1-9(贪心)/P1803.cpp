//https://www.luogu.com.cn/record/44786656
#include "bits/stdc++.h"
using namespace std;
int n,ans=1,last;
struct sec{
    int a,b;
}s[1000010];
bool cmp(const sec &a,const sec &b){return a.b<b.b;}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
    }
    sort(s+1,s+n+1,cmp);
    last=s[1].b;
    for(int i=1;i<=n;i++){
        if(last<=s[i].a){
            ans++;
            last=s[i].b;
        }
    }
    cout<<ans<<endl;
    return 0;
}