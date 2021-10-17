#include "bits/stdc++.h"
const int N=22;
using namespace std;
int n,v[100],k,vis[5000010],al,bl;
long long ans;
struct node{
    int c,x;
}a[5000010],b[5000010];
inline bool cmpa(node a,node b){
    return a.x<b.x;
}
inline bool cmpb(node a,node b){
    return a.x>b.x;
}
inline void dfs(register int t,register int x,register int c,register int f){
    if(t==k+1){
        if(!f){
            a[++al].x=x;
            a[al].c=c;
        }
        else{
            b[++bl].x=x;
            b[bl].c=c;
        }
        return;
    }
    dfs(t+1,x,c,f);
    dfs(t+1,x+v[t],c+(1<<(t-1)),f);
    dfs(t+1,x-v[t],c+(1<<(t-1)),f);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    k=n/2;
    dfs(1,0,0,0);
    k=n;
    dfs(n/2+1,0,0,1);
    sort(a+1,a+al+1,cmpa);
    sort(b+1,b+bl+1,cmpb);
    int l=1,r=1;
    while(l<=al&&r<=bl){
        while((-a[l].x)<b[r].x&&r<=bl)r++;
        int p=r;
        while(r<=bl&&-a[l].x==b[r].x){
            if(!vis[a[l].c|b[r].c]){
                vis[a[l].c|b[r].c]=1;
                ans++;
            }
            r++;
        }
        if(a[l].x==a[l+1].x&&l<al)r=p;
        l++;
    }
    cout<<ans-1<<endl;
    return 0;
}