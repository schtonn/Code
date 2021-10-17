#include "bits/stdc++.h"
using namespace std;
int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1;
		y=0;
		return a;
	}
	int d=exgcd(b,a%b,x,y);
	int temp=x;x=y;y=temp-a/b*y;
	return d;
}
bool exterior(int a,int b,int c,int &x,int &y){
	int d=exgcd(a,b,x,y);
	if(c%d)return false;
	int k=c/d;
	x*=k;
	y*=k;
	return true;
}
int main(){
	int t;
	cin>>t;
	int a,b,c,x,y;
	for(int i=1;i<=t;i++){
		x=y=0;
		cin>>a>>b>>c;
		if(exterior(a,b,c,x,y)){
			cout<<a<<'*'<<x<<'+'<<b<<'*'<<y<<'='<<c<<endl;
		}else{
			cout<<"no solution"<<endl;
		}
	}
	return 0;
}
