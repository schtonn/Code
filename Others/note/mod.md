求关于 x 的同余方程 ax ≡ 1 (mod b)的最小正整数解。
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll a,b;
void exgcd(ll a,ll b,ll &t,ll &x,ll &y){
	if(!b){t=a;x=1;y=0;}
	else{exgcd(b,a%b,t,y,x);y-=x*(a/b);}
}
ll kaola(){
	ll t,x,y;
	exgcd(a,b,t,x,y);
	return (x%b+b)%b;
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	cin>>a>>b;
	cout<<kaola()<<endl;
	return 0;
}