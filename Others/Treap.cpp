#include "bits/stdc++.h"
using namespace std;
int son[100010][2],value[100010],ran_dom[100010],size[100010],root,t;
void update(int p)
{
	size[p]=size[son[p][0]]+size[son[p][1]]+1;
}
void rotate(int &p,bool op){
	int a=son[p][!op];
	son[p][!op]=son[a][op];
	son[a][op]=p;
	update(p);
	update(a);
	p=a;
}
void insert(int &p,int v){
	if(!p){
		p=++t;
		value[p]=v;
		ran_dom[p]=rand();
		size[p]=1;
		return;
	}
	size[p]++;
	bool op=v>value[p];
	insert(son[p][op],v);
	if(ran_dom[son[p][op]]>ran_dom[p])rotate(p,!op);
}
void delet_(int &p,int v)
{
	if(v==value[p]){
		if(son[p][0]&&son[p][1]){
			bool op=ran_dom[son[p][0]]>ran_dom[son[p][1]];
			rotate(p,op),delet_(son[p][op],v);
		}
		else{
			p=son[p][0]|son[p][1];
			return;
		}
	}
	else delet_(son[p][v>value[p]],p);
	update(p);
}
int rank(int p,int v){
	if(!p)return 1;
	if(v>value[p])return rank(son[p][1],v)+size[son[p][0]]+1;
	else return rank(son[p][0],v);
}
int knar(int p,int v){
	int op=size[son[p][0]]+1;
	if(v<op)return knar(son[p][0],v);
	else if(v>op)return knar(son[p][1],v-op);
	else return value[p];
}
int pre(int p,int v){
	if(!p)return -9999999;
	if(v>value[p])return max(pre(son[p][1],v),value[p]);
	else return pre(son[p][0],v);
}
int erp(int p,int v){
	if(!p)return 9999999;
	if(v<value[p])return min(erp(son[p][0],v),value[p]);
	else return erp(son[p][1],v);
}
int main(){
	int n,op,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op>>m;
		if(op==1)insert(root,m);
		if(op==2)delet_(root,m);
		if(op==3)cout<<rank(root,m)<<endl;
		if(op==4)cout<<knar(root,m)<<endl;
		if(op==5)cout<<pre(root,m)<<endl;
		if(op==6)cout<<erp(root,m)<<endl;
	}
	return 0;
}
