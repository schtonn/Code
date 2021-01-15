//https://www.luogu.com.cn/record/44690094
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define N 100010
const double eps=1e-5;
ll n,S,T,a[N],q[N];
double t[N];
bool check(double mid){
    t[0]=0;
    for(int i=1;i<=n;i++){
        t[i]=t[i-1]+a[i]-mid;
    }
    ll h=0,b=1;
    for(int i=1;i<=n;i++){
        if(i>=S){
            while(h>=b&&t[i-S]<t[q[h]])h--;
            q[++h]=i-S;
        }
        if(b<=h){
            if(q[b]<i-T)b++;
            if(t[i]-t[q[b]]>=0)return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>S>>T;
    for(int i=1;i<=n;i++)cin>>a[i];
    double l=-10001,r=10001;
    while(r-l>eps){
        double mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    printf("%.3lf",l);
    return 0;
}