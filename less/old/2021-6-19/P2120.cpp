#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N=1000010;
ll n,x[N],p[N],c[N],sump[N],sumxp[N],f[N],q[N],head,tail;
double cal(int i,int j){
    return (double)(f[i]+sumxp[i]-(f[j]+sumxp[j]))/(sump[i]-sump[j]);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>p[i]>>c[i];
        sump[i]=sump[i-1]+p[i];
        sumxp[i]=sumxp[i-1]+x[i]*p[i];
    }
    for(int i=1;i<=n;i++){
        while(head<tail&&cal(q[head],q[head+1])<x[i])head++;
        f[i]=f[q[head]]+x[i]*(sump[i]-sump[q[head]])-(sumxp[i]-sumxp[q[head]])+c[i];
        while(head<tail&&cal(i,q[tail-1])<cal(q[tail-1],q[tail]))tail--;
        q[++tail]=i;
    }
    cout<<f[n]<<endl;
    return 0;
}