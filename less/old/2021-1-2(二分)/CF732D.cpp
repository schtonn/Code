//https://www.luogu.com.cn/record/44544813
#include "bits/stdc++.h"
using namespace std;
#define N 100010
int n,m,a[N],d[N];
bool done[N];
bool check(int mid){
    int cost=0;
    memset(done,0,sizeof(done));
    for(int i=mid;i>=1;i--){
        if(d[i]&&!done[d[i]]){
            cost+=a[d[i]];
            done[d[i]]=true;
        }else if(cost)cost--;
    }
    if(cost)return false;//still need revise
    for(int i=1;i<=m;i++){
        if(!done[i])return false;//not all subjects
    }
    return true;//all ok
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>d[i];
    for(int i=1;i<=m;i++)cin>>a[i];
    int l=m,r=n,ret=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
            ret=mid;
        }
        else l=mid+1;
    }
    cout<<ret<<endl;
    return 0;
}