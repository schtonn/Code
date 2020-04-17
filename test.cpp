#include "bits/stdc++.h"
using namespace std;
struct mengbier{
	bool face;
	string name;
}toy[100010];
int n,m,a,s,p;
int sum[100010],gg[100010];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>toy[i].face>>toy[i].name;
	}
	for(int i=0;i<m;i++){
		cin>>a>>s;
		int f=toy[p].face;
		p=(((!f)&&(!a))||(f&&a))?(p-s+n)%n:(p+s+n)%n;
	}
	cout<<toy[p].name<<endl;
	for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + gg[i];
while(m--)
{
    int L, R; scanf("%d%d", &L, &R);
    printf("%d\n", sum[R] - sum[L - 1]);
}
}