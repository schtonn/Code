#include<bits/stdc++.h>
using namespace std;
const int N=100010;
vector<int>v[N];
int T,a[N],h[N];
bool flag;
struct node{
    int a,b;
};
node dfs(int now,int pre){
    if(!flag)return{0,0};
    node p={0,a[now]};
    for(auto&to:v[now]){
        if(to==pre)continue;
        node tmp=dfs(to,now);
        p.a+=tmp.a;
        p.b+=tmp.b;
    }
    int x=p.a+p.b+h[now];
    if(x&1){
        flag=false;
        return{0,0};
    }
    x/=2;
    if(x<p.a||x>p.a+p.b){
        flag=false;
        return{0,0};
    }
    return node{x,p.a+p.b-x};
}
int main(){
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            v[i].clear();
        }
        for(int i=1;i<=n;i++)cin>>h[i];
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        flag=true;
        dfs(1,0);
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}