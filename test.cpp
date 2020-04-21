#include "bits/stdc++.h"
using namespace std;
int price[10000],n,b,k,sum;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>price[i];
	}
	cin>>b>>k;
	sort(price+1,price+1+n);
	for(int i=n;i>n-k;i--){
		sum+=price[i];
		if(sum>b){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}