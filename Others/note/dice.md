## D929. 垒骰子
### 时间限制：1.0s   内存限制：256.0MB   代码提交间隔：5分钟(现在可以提交)  
### 问题描述
　　赌圣atm晚年迷恋上了垒骰子，就是把骰子一个垒在另一个上边，不能歪歪扭扭，要垒成方柱体。

　　经过长期观察，atm 发现了稳定骰子的奥秘：有些数字的面贴着会互相排斥！

　　我们先来规范一下骰子：1 的对面是 4，2 的对面是 5，3 的对面是 6。

　　假设有 m 组互斥现象，每组中的那两个数字的面紧贴在一起，骰子就不能稳定的垒起来。

　　atm想计算一下有多少种不同的可能的垒骰子方式。

　　两种垒骰子方式相同，当且仅当这两种方式中对应高度的骰子的对应数字的朝向都相同。

　　由于方案数可能过多，请输出模 10^9 + 7 的结果。

　　不要小看了 atm 的骰子数量哦～
### 输入格式
　　第一行两个整数 n m　　n表示骰子数目　　接下来 m 行，每行两个整数 a b ，表示 a 和 b 数字不能紧贴在一起。
### 输出格式
　　一行一个数，表示答案模 10^9 + 7 的结果。
### 样例输入
```
2 1
1 2
```
### 样例输出
```
544
```
### 数据规模和约定
- 对于 30% 的数据：n <= 5
- 对于 60% 的数据：n <= 100
- 对于 100% 的数据：0 < n <= 10^9, m <= 36

```cpp
#include "bits/stdc++.h"
using namespace std;
const int mod=int(1e9)+7;
int n,m,s[7]={0,4,5,6,1,2,3},a[7][7],b[7][7],ans[7][7],sum=0;
int qpow(int a2){
	int ans=1;
	for(int a1=4;a2;a2>>=1,a1=(long long)a1*a1%mod){
		if(a2&1){
			ans=(long long)ans*a1%mod;
		}
	}
	return ans;
}
void copy(int a1[7][7],int a2[7][7])
{
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			a1[i][j]=a2[i][j];
		}
	}
}
void mul(int a1[7][7],int a2[7][7]){
	for(int i=1;i<=6;i++){
		for(int j=1;j<=6;j++){
			ans[i][j]=0;
			for(int k=1;k<=6;k++){
				ans[i][j]=(ans[i][j]+(long long)a1[i][k]*a2[k][j]%mod)%mod;
			}
		}
	}
}
int main()
{
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			a[i][j]=b[i][j]=1;
		}
	}
	cin>>n>>m;
	if(n==1)
	{
		cout<<24<<endl;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int a1,a2;
		cin>>a1>>a2;
		a[s[a1]][a2]=a[s[a2]][a1]=b[s[a1]][a2]=b[s[a2]][a1]=0;
	}
	int t=qpow(n);
	n-=2;
	for(;n;n>>=1,mul(a,a),copy(a,ans))
	{
		if(n&1)
		{
			mul(b,a),copy(b,ans);
		}
	}
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			sum=((long long)sum+b[i][j])%mod;
		}
	}
	cout<<(long long)sum*t%mod<<endl;
	return 0;
}
```