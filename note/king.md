问题描述
　　恰逢 H 国国庆，国王邀请 n 位大臣来玩一个有奖游戏。首先，他让每个大臣在左、右手上面分别写下一个整数，国王自己也在左、右手上各写一个整数。然后，让这 n 位大臣排成一排，国王站在队伍的最前面。排好队后，所有的大臣都会获得国王奖赏的若干金币，每位大臣获得的金币数分别是：排在该大臣前面的所有人的左手上的数的乘积除以他自己右手上的数，然后向下取整得到的结果。
　　国王不希望某一个大臣获得特别多的奖赏，所以他想请你帮他重新安排一下队伍的顺序，
　　使得获得奖赏最多的大臣，所获奖赏尽可能的少。注意，国王的位置始终在队伍的最前面。
输入格式
　　第一行包含一个整数 n，表示大臣的人数。
　　第二行包含两个整数 a 和 b，之间用一个空格隔开，分别表示国王左手和右手上的整数。 接下来 n 行，每行包含两个整数 a 和 b，之间用一个空格隔开，分别表示每个大臣左手和右手上的整数。
输出格式
　　输出只有一行，包含一个整数，表示重新排列后的队伍中获奖赏最多的大臣所获得的金币数。

#include "bits/stdc++.h"
using namespace std;
#define N 10000
struct big{
	static const int digit=4,base=10000;
	static char s[N<<2];
	int num[N];
	big(){memset(num,0,sizeof(num));num[0]=1;}
	void print(){
		cout<<num[num[0]];
		for(int i=num[0]-1;i>0;i--){
			printf("%0*d",digit,num[i]);
		}
	}
	bool operator<(const big &cmp)const{
		if(num[0]-cmp.num[0])return num[0]<cmp.num[0];
		for(int i=num[0];i>0;i--){
			if(num[i]-cmp.num[i])return num[i]<cmp.num[i];
		}
		return 0;
	}
	big operator*(const int &x)const{
		big b;
		b.num[0]=num[0];
		for(int i=1;i<=num[0];i++){
			b.num[i]+=num[i]*x,b.num[i+1]+=b.num[i]/base,b.num[i]%=base;
		}
		while(b.num[b.num[0]+1]) ++b.num[0];
		return b;
	}
	big operator/(const int &x)const{
		big b=*this;
		for(int i=num[0];i>=2;i--) b.num[i-1]+=b.num[i]%x*base,b.num[i]/=x;
		b.num[1]/=x;
		while(b.num[0]>1&&!b.num[b.num[0]]) --b.num[0];
		return b;
	}
}t,ans,tmp;
char big::s[N<<2];
struct iny{int a,b;}x[1001];
bool cmp(iny a,iny b){return a.a*a.b<b.a*b.b;}
int a,b,n;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++) cin>>x[i].a>>x[i].b;
	sort(x+1,x+n+1,cmp),t.num[1]=a,t.num[0]=1;
	for(int i=1;i<=n;i++) tmp=t/x[i].b,ans=max(ans,tmp),t=t*x[i].a;
	ans.print();
	return 0;
}
