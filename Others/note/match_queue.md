### 问题描述
　　涵涵有两盒火柴,每盒装有 n 根火柴,每根火柴都有一个高度。现在将每盒中的火柴各自排成一列,同一列火柴的高度互不相同,两列火柴之间的距离定义为:$\sum_{i=1}^n{(a_i−b_i)^2}$,其 中 ai 表示第一列火柴中第 i 个火柴的高度,bi 表示第二列火柴中第 i 个火柴的高度。

　　每列火柴中相邻两根火柴的位置都可以交换,请你通过交换使得两列火柴之间的距离最 小。请问得到这个最小的距离,最少需要交换多少次?如果这个数字太大,请输出这个最 小交换次数对 99,999,997 取模的结果。

### 输入格式

　　共三行,第一行包含一个整数 n,表示每盒中火柴的数目。

　　第二行有 n 个整数,每两个整数之间用一个空格隔开,表示第一列火柴的高度。 第三行有 n 个整数,每两个整数之间用一个空格隔开,表示第二列火柴的高度。

### 输出格式

　　输出共一行,包含一个整数,表示最少交换次数对 99,999,997 取模的结果。

### 输入样例
```
　　4
　　2 3 1 4
　　3 2 1 4
```
### 输出样例
```
　　1
```
### 样例说明

　　最小距离是 0,最少需要交换 1 次,比如:交换第 1 列的前 2 根火柴或者交换第 2 列的前 2 根火柴。 【输入输出样例 2】

### 输入样例
```
　　4
　　1 3 4 2
　　1 7 2 4
```
### 输出样例
```
　　2
```
### 样例说明
　　最小距离是 10,最少需要交换 2 次,比如:交换第 1 列的中间 2 根火柴的位置,再交
　　换第 2 列中后 2 根火柴的位置。
### 数据规模和约定
```
　　对于 10%的数据, 1 ≤ n ≤ 10;
　　对于 30%的数据,1 ≤ n ≤ 100;
　　对于 60%的数据,1 ≤ n ≤ 1,000;
　　对于 100%的数据,1 ≤ n ≤ 100,000,0 ≤火柴高度≤ 231 − 1。
```
```cpp
#include "bits/stdc++.h"
using namespace std;
#define N 100010
const int mod=99999997;
inline int read(){
	int ans=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>'0'&&ch<'9'){ans=ans*10+ch-'0';ch=getchar();}
	return ans;
}
struct node{
	int dat;
	int loc;
}a[N],b[N];
int t[N],s[N],n,ans;
bool cmp(node a,node b){
	return a.dat<b.dat;
}
inline int lowbit(int x){
	return x&-x;
}
void change(int x,int c){
	while(x<=n){
		t[x]=(t[x]+c)%mod;
		x+=lowbit(x);
	}
}
int query(int x){
	int ans=0;
	while(x){
		ans=(ans+t[x])%mod;
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].dat=read();
		a[i].loc=i;
	}
	for(int i=1;i<=n;i++){
		b[i].dat=read();
		b[i].loc=i;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[a[i].loc]=b[i].loc;
	}
	for(int i=1;i<=n;i++){
		change(s[i],1);
		ans+=i-query(s[i]);
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
```