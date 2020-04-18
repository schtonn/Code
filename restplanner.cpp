#include"bits/stdc++.h"
using namespace std;
int a[200],b[200],n,m,op,x,y;
int main(){
	freopen("testdata.in","r",stdin);
	freopen("ghostdata.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++){
		cin>>op>>x>>y;
		if(op==1){
			for(int j=x;j<=y;j++){
				a[j]=a[j]+b[j];
			}
		}
		else if(op==2){
			for(int j=x;j<=y;j++){
				b[j]=a[j]+b[j];
			}
		}
		else{
			int sum=0;
			for(int j=x;j<=y;j++){
				sum=(sum+10301+(a[j]*b[j])%10301)%10301;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}