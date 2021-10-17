#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll n,m,a[50],ans;
vector<ll>L,R;
void dfs(int l,int r,ll st,vector<ll>&u){
    if(st>m)return;
    if(l>r){
        u.push_back(st);
        return;
    }
    dfs(l+1,r,st+a[l],u);
    dfs(l+1,r,st,u);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,n/2,0,L);
    dfs(n/2+1,n,0,R);
    sort(L.begin(),L.end());
    for(int i=0;i<(int)R.size();i++){
        ans+=upper_bound(L.begin(),L.end(),m-R[i])-L.begin();
    }
    cout<<ans<<endl;
    return 0;
}