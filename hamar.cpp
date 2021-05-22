#include "bits/stdc++.h"
using namespace std;
int n,m,t[1000010];
int lb(int x){return x&-x;}
void add(int x,int d){
    while(x<=n){
        t[x]+=d;
        x+=lb(x);
    }
}
int sum(int x){
    int ans=0;
    while(x){
        ans+=t[x];
        x-=lb(x);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    int a,pre=0;
    for(int i=1;i<=n;i++){
        cin>>a;
        add(i,a-pre);
        pre=a;
    }
    int o,x,y;
    while(m--){
        cin>>o;
        if(!o){
            cin>>x>>y;
            add(x,1);
            add(y+1,-1);
        }else{
            cin>>x;
            cout<<sum(x)<<endl;
        }
    }
    return 0;
}