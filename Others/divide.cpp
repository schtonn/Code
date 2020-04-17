#include "bits/stdc++.h"
using namespace std;
long long n,m,p,bsize,book[100010],a[100010],sum[100010],fc[100010],fa[100010],op,x,y,k;
void pushdown(int bla){
	for(int i=(bla-1)*bsize+1;i<=bla*bsize;i++){
		a[i]=a[i]*fc[bla]+fa[bla];
		fa[bla]=0;
		fc[bla]=1;
	}
}
void mul(long long l,long long r,long long c){
	//incomplete---][-----][---complete--][-----][---incomplete
	long long End=min(r,book[l]*bsize);
	for(long long i=l;i<=End;i++){
		a[i]*=c;
		sum[book[i]]+=(c-1)*a[i];
	}
	for(long long i=book[l]+1;i<=book[r]-1;i++){
		sum[i]=(sum[i]*c);
		fc[i]*=c;
		fa[i]*=c;
	}
	if(book[l]!=book[r]){
		for(long long i=(book[r]-1)*bsize+1;i<=r;i++){
			sum[book[i]]+=(c-1)*a[i];
			a[i]*=c;
		}
	}
}
void add(long long l,long long r,long long c){
	//incomplete---][-----][---complete--][-----][---incomplete
	long long End=min(r,book[l]*bsize);
	pushdown(book[l]);
	for(long long i=l;i<=End;i++){
		a[i]+=c;
		sum[book[i]]+=c;
	}
	for(long long i=book[l]+1;i<=book[r]-1;i++){
		sum[i]=(sum[i]+c*bsize);
		fa[i]+=c;
	}
	if(book[l]!=book[r]){
		pushdown(book[r]);
		for(long long i=(book[r]-1)*bsize+1;i<=r;i++){
			a[i]+=c;
			sum[book[i]]+=c;
		}
	}
}
long long query(long long l,long long r){
	long long res=0;
	long long End=min(r,book[l]*bsize);
	for(long long i=l;i<=End;i++){
		res+=a[i]*fc[book[i]]+fa[book[i]];
	}
	for(long long i=book[l]+1;i<=book[r]-1;i++){
		res+=sum[i];
	}
	if(book[l]!=book[r]){
		for(long long i=(book[r]-1)*bsize+1;i<=r;i++){
			res+=a[i]*fc[book[i]]+fa[book[i]];
		}
	}
	return res;
}
int main(){
	cin>>n>>m>>p;
	bsize=sqrt(n);
	for(long long i=1;i<=n;i++)book[i]=(i-1)/bsize+1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum[book[i]]+=a[i];
		fc[i]=1;
	}
	while(m--){
		cin>>op;
		if(op==1){
			cin>>x>>y>>k;
			mul(x,y,k);
		}else if(op==2){
			cin>>x>>y>>k;
			add(x,y,k);
		}else{
			cin>>x>>y;
			cout<<query(x,y)<<endl;
		}
	}
	system("pause");
	return 0;
}