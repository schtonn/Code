#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll n,L,p[50010],f[50010],a[50010],b[50010],q[50010],head,tail;
double cal(int i,int j){
    double dy=f[i]+b[i]*b[i]-f[j]-b[j]*b[j],dx=b[i]-b[j];
    return dy/dx;
}
int main(){
    cin>>n>>L;
    for(int i=1;i<=n;i++){
        ll t;
        cin>>t;
        p[i]=p[i-1]+t;
    }
    for(int i=0;i<=n;i++){
        a[i]=p[i]+i;
        b[i]=p[i]+i+L+1;
    }
    for(int i=1;i<=n;i++){
        while(head<tail&&cal(q[head],q[head+1])<2*a[i])head++;
        f[i]=f[q[head]]+(a[i]-b[q[head]])*(a[i]-b[q[head]]);
        while(head<tail&&cal(i,q[tail-1])<cal(q[tail-1],q[tail]))tail--;
        q[++tail]=i;
    }
    cout<<f[n]<<endl;
    return 0;
}