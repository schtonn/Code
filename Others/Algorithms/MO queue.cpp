// #include<iostream>
// #include<cstdio>
// #include<algorithm>
// #include<cstring>
// #include<cmath>
// #define maxn 50050
// using namespace std;
// int c[maxn],cnt[maxn],ans;
// int n,m,ct,len;
// char op;
// int num[maxn];
// struct Query{
// 	int l,r,in,id,ct;
// 	bool operator < (const Query &a)const{
// 		if(in==a.in){
// 			return r<a.r;
// 	  }
// 		return in<a.in;
// 	}
// }q[maxn];
// int a[maxn],pos[maxn],c[maxn];
// void ins(int x){
// 	ans-=cnt[c[x]]*cnt[c[x]];
// 	cnt[c[x]]++;
// 	ans+=cnt[c[x]]*cnt[c[x]];
// }
// void del(int x){
// 	ans-=cnt[c[x]]*cnt[c[x]];
// 	cnt[c[x]]--;
// 	ans+=cnt[c[x]]*cnt[c[x]];
// } 
// void change(int id,int l,int r){
// 	if(l<=pos[id]&&pos[id]<=r){
// 		ans-=c[a[pos[id]]];
// 		c[a[pos[id]]]--;
// 		c[c[id]]++;
// 		ans+=c[a[pos[id]]];
// 	}
// 	swap(a[pos[id]],c[id]);
// }
// int main(){
// 	cin>>n>>m;
// 	len=sqrt(n);
// 	for(int i=1;i<=n;i++){
// 		cin>>c[i];
// 	}
// 	for(int i=1;i<=m;i++){
// 		int x,y;
// 		cin>>op>>x>>y; 
// 		if(op=='Q'){
//  			q[i].l=x;
//  			q[i].r=y;
//  			q[i].in=(x)/len;
//  			q[i].id=i;
// 			q[i].ct=ct;
// 		}else{
// 			ct++;
// 		}
// 	}
// 	sort(q+1,q+1+m);
// 	int l=1,r=0;
// 	for(int i=1;i<=m;i++){
// 		int x=q[i].l;
// 		int y=q[i].r;
// 		while(l<x)del(l),++l;
// 		while(l>x)ins(l-1),--l;
// 		while(r<y)ins(r+1),++r;
// 		while(r>y)del(r),--r;
// 		while(ct>q[i].ct)change(ct--,x,y);
// 		while(ct<q[i].ct)change(++ct,x,y);
// 		num[q[i].id]=ans;
// 	}
// 	for(int i=1;i<=m;i++){
// 		cout<<num[i]<<endl;
// 	}
// 	return 0;
// }
#include<bits/stdc++.h>
#define maxn 500050
using namespace std;
int c[maxn],cnt[maxn],sum,fa;
int n,m,bsize;
int num[maxn];
struct Query{
	int l,r,k,id;
    bool operator < (Query& T)
    {
        return l/bsize==T.l/bsize?r<T.r:l<T.l;
    }
}q[maxn];
int main(){
	freopen("snake7.in","r",stdin);
	freopen("snake7.out","w",stdout);
	cin>>n>>m; 
	bsize=sqrt(n);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<m;i++){
		cin>>q[i].l>>q[i].r>>q[i].k;	
		q[i].id=i;
	}
	sort(q,q+m);
	int l=1,r=0;
	for(int i=0;i<m;i++){
		int x=q[i].l;
		int y=q[i].r;
		while(l<x)--cnt[c[l++]];
		while(l>x)++cnt[c[--l]];
		while(r<y)++cnt[c[++r]];
		while(r>y)--cnt[c[r--]];
		num[q[i].id]=cnt[q[i].k];
	}
	for(int i=0;i<m;i++){
		cout<<num[i]<<endl;
	}
	return 0;
}
