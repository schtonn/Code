请你统计s、t之间（含）所有形如n=a^m+b^k的数的个数，其中a和b是非负整数，m和k都是大于1的正整数。

#include<iostream>
#include<algorithm> 
#define N 5000010
int num[10000],ans;
bool is[N],vis[N];
using namespace std;
int main(){
	freopen("perfect.in","r",stdin);
	freopen("perfect.out","w",stdout);
	int s,t,cnt=2;
	cin>>s>>t;
	vis[0]=vis[1]=1;num[1]=0;num[2]=1;
	for(int i=2;i*i<=t;i++){
		long long p=i*i;
		while(p<=t){
			if(!vis[p]){
				vis[p]=1;
				num[++cnt]=p;
			}
			p*=i;
		}
	}
	sort(num+1,num+cnt+1);
	for(int i=1;i<=cnt;i++){
		for(int j=i;j<=cnt&&num[i]+num[j]<=t;j++){
			is[num[i]+num[j]]=1;
		}
	}
	for(int i=s;i<=t;i++){
		ans+=is[i];
	}
	cout<<ans<<endl;
	return 0;
}