#include "bits/stdc++.h"
using namespace std;
const int N=100010;
int c1[N],c2[N];
int n,p;
int main(){
	freopen("running.in","r",stdin);
	freopen("running.out","w",stdout);
	cin>>n>>p;
	for(int i=0;i<=n;i++){
		c1[i]=1;
		c2[i]=0;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k+j<=n;k+=i){
				c2[k+j]=(c2[k+j]+c1[j])%p;
			}
		}
		for(int j=0;j<=n;j++){
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
	cout<<c1[n]<<endl;
	return 0;
}