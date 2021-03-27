#include "bits/stdc++.h"
using namespace std;
const int N=1010;
int n,a[N][N],l[N],u[N],r[N],d[N],id,mx,ans;
inline void upd(int x){
    l[x]=r[x]=u[x]=d[x]=0;
    for(register int i=0;i<x-1;i++){
        l[x]+=a[x-i][i+1];
        r[x]+=a[n-x+1+i][n-i];
    }
    for(register int i=0;i<n-x;i++){
        u[x]+=a[i+1][x+i];
        d[x]+=a[n-i][n-x+1-i];
    }
}
inline int getmax(){
    mx=-1;
    for(register int i=1;i<=n;i++){
        int num=l[i]+u[i]+r[i]+d[i];
        if(num>mx){
            id=i;
            mx=num;
        }
    }
    return mx;
}
int main(){
    ios::sync_with_stdio(false);
    // freopen("pacman.in","r",stdin);
    // freopen("pacman.out","w",stdout);
    cin>>n;
    for(register int i=1;i<=n;i++){
        for(register int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(register int i=2;i<n;i++){
        upd(i);
    }
    for(register int i=1;i<=n;i++){
        u[1]+=a[i][i];
        l[n]+=a[n-i+1][i];
    }
    ans+=getmax();
    for(register int i=0;i<id;i++){
        a[id-i][i+1]=0;
        a[n-id+1+i][n-i]=0;
    }
    for(register int i=0;i<n-id;i++){
        a[i+1][id+i]=0;
        a[n-i][n-id+1-i]=0;
    }
    for(register int i=2;i<n;i++){
        upd(i);
    }
    u[1]=l[n]=0;
    for(register int i=1;i<=n;i++){
        u[1]+=a[i][i];
        l[n]+=a[n-i+1][i];
    }
    ans+=getmax();
    cout<<ans<<endl;
    return 0;
}
/*
4
20 1 19 2
3 18 4 17
16 5 15 6
7 14 8 13
*/