#include "bits/stdc++.h"
using namespace std;
int n,m,q,p[1010][1010];
bool check(int x,int y,int k,int d){
    int cnt=0;
    for(int i=max(x-d,0);i<=min(x+d,n);i++){
        for(int j=max(y-d,0);j<=min(y+d,n);j++){
            if(p[i][j]&&abs(i-x)+abs(j-y)<=d)cnt++;
            if(cnt>=k)return true;
        }
    }
    return false;
}
int main(){
    int x,y,k;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=n;j++){
            if(s[j-1]=='*'){
                p[i][j]=1;
            }
        }
    }
    while(q--){
        cin>>x>>y>>k;
        int l=0,r=n*2;
        if(!check(x,y,k,r)){
            cout<<-1<<endl;
            continue;
        }
        while(l<r){
            int mid=(l+r)>>1;
            if(check(x,y,k,mid))r=mid;
            else l=mid+1;
        }
        cout<<r<<endl;
    }
    return 0;
}