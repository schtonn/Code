#include "bits/stdc++.h"
using namespace std;
const long long mod=99999999;
long long base[7][7]={
	{0,1,0,0,2,0,5},
	{1,0,0,0,3,2,3},
	{1,0,0,0,0,0,0},
	{0,1,0,0,0,0,0},
	{0,0,1,0,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,0,0,0,1},
};
struct matrix{
	long long v[30][30];
	long long x,y;
};
matrix operator+(matrix a,matrix b){
	matrix c;
	if(a.x!=b.x||a.y!=b.y)return c;
	long long x=a.x,y=a.y;
	c.x=x;c.y=y;
	for(long long i=0;i<x;i++){
		for(long long j=0;j<y;j++){
			c.v[i][j]=a.v[i][j]+b.v[i][j];
		}
	}
	return c;
}
matrix operator-(matrix a,matrix b){
	matrix c;
	if(a.x!=b.x||a.y!=b.y)return c;
	long long x=a.x,y=a.y;
	c.x=x;c.y=y;
	for(long long i=0;i<x;i++){
		for(long long j=0;j<y;j++){
			c.v[i][j]=a.v[i][j]-b.v[i][j];
		}
	}
	return c;
}
matrix operator*(matrix a,matrix b){
	matrix c;
	if(a.y!=b.x)return c;
	long long x=a.x,y=b.y,z=a.y;
	c.x=x;c.y=y;
	for(long long i=0;i<x;i++){
		for(long long j=0;j<y;j++){
			c.v[i][j]=0;
			for(long long k=0;k<z;k++){
				c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j]+mod)%mod;
			}
		}
	}
	return c;
}
void init(matrix &a){
	for(long long i=0;i<a.x;i++){
		for(long long j=0;j<a.y;j++){
			a.v[i][j]=base[i][j];
		}
	}
}
ostream& operator<<(ostream& ous,matrix a){
	for(long long i=0;i<a.x;i++){
		for(long long j=0;j<a.y;j++){
			ous<<a.v[i][j]<<' ';
		}
		ous<<endl;
	}
	return ous;
}
long long n;
matrix& operator *=(matrix &a,matrix n){
	a=a*n;
	return a;
}
matrix a,ans;
int main(){
	cin>>n;
	a.x=a.y=7;
	init(a);
	ans.x=7;ans.y=1;
	ans.v[0][0]=6;
	ans.v[1][0]=5;
	ans.v[2][0]=1;
	ans.v[3][0]=4;
	ans.v[4][0]=2;
	ans.v[5][0]=3;
	ans.v[6][0]=1;
	if(n==1){
		cout<<2<<endl<<3;
	}else if(n==2){
		cout<<1<<endl<<4;
	}else if(n==3){
		cout<<6<<endl<<5;
	}
	if(n<4)return 0;
	n-=3;
	while(n){
		if(n&1)ans=a*ans;
		a*=a;
		n>>=1;
	}
	cout<<ans.v[0][0]<<endl<<ans.v[1][0];
	return 0;
}