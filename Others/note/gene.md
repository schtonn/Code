## D1029. 基因计数（加强版）
```
时间限制：1.0s   内存限制：256.0MB
试题来源：北师大实验中学 周尚
```
### 问题描述
　　给定一个碱基序列,问长度为L的包含这段碱基序列的基因有多少种？注意基因只由A、T、G、C四种碱基组成,如果表达出来不同,则认为是不同的基因。
### 输入格式
　　输入的第一行包含一个字符串,表示给定的碱基序列。

　　第二行包含一个整数L。
### 输出格式
　　输出一个整数,表示答案对123456789取余的结果。
### 样例输入
```
ATAT
6
```
### 样例输出
```
47
```
### 数据规模和约定
　　对于$10\%$的评测用例,$1\leq字符串长度\leq10, 1\leq L\leq10$。

　　对于$20\%$的评测用例,$1\leq字符串长度\leq10, 1\leq L\leq100$。

　　对于$50\%$的评测用例,$1\leq字符串长度\leq100,1\leq L\leq10000$。

　　对于$100\%$的评测用例,$1\leq字符串长度\leq100,1\leq L\leq10^18$。
  

## 解决过程
通过前后缀匹配求出递推关系，转化为矩阵后进行矩阵快速幂。
![image](https://user-images.githubusercontent.com/60652675/77222766-11b92e00-6b91-11ea-80c7-89f9dd48578a.png)
![image](https://user-images.githubusercontent.com/60652675/77222833-f995de80-6b91-11ea-9032-9a863b4ba078.png)

```cpp
#include "bits/stdc++.h"
using namespace std;
long long len,l,temp[1010],base[110][110];
char ch[1000];
const long long mod=123456789;
struct matrix{
	long long v[110][110];
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
long long pre(long long step,long long add){
	long long ans=0;
	for(long long i=1;i<=step;i++){
		long long flag=1;
		for(long long j=1;j<=i;j++){
			if(j==i){
				if(add!=temp[j])flag=0;
			}else{
				if(temp[step-i+j]!=temp[j])flag=0;
			}
		}
		if(flag)ans=i;
	}
	return ans;
}
void init(){
	for(long long i=0;i<=len-1;i++){
		for(long long j=1;j<=4;j++){
			base[pre(i+1,j)][i]++;
		}
	}
}
void tran(matrix &a){
	for(long long i=0;i<a.x;i++){
		for(long long j=0;j<a.y;j++){
			a.v[i][j]=base[j][i]%mod;
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
long long qpow(long long a,long long n){
	long long ans=1;
	while(n){
		if(n&1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans%mod;
}
long long n;
matrix& operator *=(matrix &a,matrix n){
	a=a*n;
	return a;
}
matrix a,ans;
int main(){
	cin>>ch>>l;
	len=strlen(ch);
	for(long long i=0;i<len;i++){
		if(ch[i]=='A')temp[i+1]=1;
		else if(ch[i]=='T')temp[i+1]=2;
		else if(ch[i]=='G')temp[i+1]=3;
		else if(ch[i]=='C')temp[i+1]=4;
	}
	a.x=a.y=len;
	init();
	tran(a);
	ans.x=1,ans.y=len;
	ans.v[0][0]=1;
	n=l;
	while(n){
		if(n&1)ans*=a;
		a*=a;
		n>>=1;
	}
	long long trueans=0;
	for(long long i=0;i<len;i++){
		trueans=(trueans+ans.v[0][i])%mod;
	}
	cout<<(qpow(4,l)-trueans+mod)%mod<<endl;
	return 0;
}
```