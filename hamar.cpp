#include "bits/stdc++.h"
using namespace std;
string a,b,c[1010];
int alen,blen,clen,junk[1010],ans;
int main(){
    freopen("Topfox.in","r",stdin);
    freopen("Topfox.out","w",stdout);
    cin>>a>>b;
    alen=a.length();
    blen=b.length();
    for(int i=1;i<=alen;i++){
        for(int j=1;j<=blen;j++){
            c[clen++]=a.substr(0,i)+b.substr(0,j);
        }
    }
    for(int i=0;i<clen;i++){
        if(junk[i])continue;
        for(int j=i+1;j<clen;j++){
            if(junk[j])continue;
            if(c[i]==c[j])junk[j]=1;
        }
    }
    for(int i=0;i<clen;i++){
        if(!junk[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}