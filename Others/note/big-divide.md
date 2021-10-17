给出一个正整数n，求一个和最大的序列a0，a1，a2，……，ap，满足n=a0>a1>a2>……>ap且ai+1是ai的约数，输出a1+a2+……+ap的最大值
$\text$


#include "bits/stdc++.h"
using namespace std;
int mod(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)return i;
	}
	return n;
}
int main(){
	int a,ans=0;
	cin>>a;
	while(a!=1){
		a/=mod(a);
		ans+=a;
	}
	cout<<ans<<endl;
	return 0;
}