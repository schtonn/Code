#include "bits/stdc++.h"
using namespace std;
const int N=1010,M=1010;
int n,m,a[N],b[N],c[M],lef[N],sum[N],hsum[N],tsum[N];
bool check(int rows){
    for(int i=1;i<=n;i++){
        if(b[i]-hsum[i]-sum[i]*rows<0)return false;
    }
    return true;
}
bool checktail(int rows){
    for(int i=1;i<=n;i++){
        if(lef[i]<0)return false;
    }
    return true;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum[c[i]]+=a[i];
        hsum[c[i]]=sum[c[i]];
    }
    for(int i=1;i<=n;i++){
        int l=0,r=N,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid))l=mid+1;
            else r=mid-1;
        }
        for(int j=1;j<=m;j++)lef[j]=b[i]-hsum[i]-sum[i]*mid;
        int tail=0;
        while(checktail(tail)){
            tail++;
            lef[c[tail]]-=a[tail];
        }
        tail--;
        cout<<n-i+mid*n+tail<<endl;
        hsum[c[i]]-=a[i];
    }
    return 0;
}