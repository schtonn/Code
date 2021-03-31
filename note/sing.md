```cpp
时间限制：1.0s   内存限制：512.0MB   代码提交间隔：5分钟(现在可以提交)  
试题来源：NOIP2004 提高组 第一天第三题
问题描述
　　N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK， 则他们的身高满足T1<...<Ti>Ti+1>…>TK(1<=i<=K)。
　　你的任务是，已知 所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
输入格式
　　输入的第一行是一个整数N(2<=N<=100)，表示同学的总数。第二行有N个整数，用空格分隔，第i个整数Ti(130<=Ti<=230)是第i位同学的身高(厘米)。
输出格式
　　输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。
样例输入
8
186 186 150 200 160 130 197 220
样例输出
4
蛤蟆，一只蛤蟆跳跳




#include<iostream>
#include<algorithm>
using namespace std;
#define N 105    
int f1[N],f2[N];
int a[N];
int main(){
	int n; cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		f1[i]=1;
		for(int j=1;j<i;j++){
			if(a[i]>a[j])f1[i]=max(f1[i],f1[j]+1);    
		}
	}
	for(int i=1;i<=n;i++){
		f2[i]=1;
		for(int j=1;j<i;j++){
			if(a[i]<a[j])f2[i]=max(f2[i],max(f1[j],f2[j])+1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,max(f1[i],f2[i]));
	}
	cout<<n-ans;
	return 0;
}
```