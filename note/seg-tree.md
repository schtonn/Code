1. 线段树中，query的两重相加操作
```cpp
return query(lson,l,t[lson].r)+query(rson,t[rson].l,r);
```
与update的两重相加操作性质是一样的
```cpp
t[id].sum=t[lson].sum+t[rson].sum;
```
都是通过子节点的值求出父节点的值
2. 然而，对于一颗线段树，他在求值的时候返回的并不是完整的子节点，而只是那个区间的部分，所以在query中直接使用update有时候会出现问题。
3. 对拍在找不到问题时是很有用的一项措施


# Dk6a7. 线段树基础练习3

>> 时间限制：1.0s   内存限制：512.0MB   代码提交间隔：5分钟(现在可以提交) 

试题来源：基础练习

### 问题描述

　　输入分成n格的木板的初始染色情况（每格非黑即白）。维护m个操作，操作分2类：

　　（1）：对于其中连续一段，改变每一格的颜色

　　（2）：对于其中连续一段，询问它包含多少段同色段

### 输入格式

　　第一行：n m

　　接下去n行：a[1],a[2],a[3]…a[n]

　　接下去m行：每行“1 l r”表示修改或者“2 l r"表示查询。

### 输出格式

　　每个查询用一行输出。

### 样例输入
```
1 1
1
2 1 1
```
### 样例输出
```
1
```
### 数据规模和约定
```
n,m<=100000
```

```cpp
#include"iostream"
using namespace std;
#define N 1010
#define lson id<<1
#define rson id<<1|1
int a[N],n,m,op,x,y,k;
int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node{
	int l,r,sum;
	bool lazy,lc,rc;
}t[4*N];
void pushdown(int id){
	if(t[id].lazy){
		cout<<"down: "<<id<<endl;
		t[lson].lazy=!t[lson].lazy;
		t[rson].lazy=!t[rson].lazy;
		t[id].lc=!t[id].lc;
		t[id].rc=!t[id].rc;
		t[id].lazy=0;
	}
}
void update(int id){
	cout<<"up: "<<id;
	t[id].lc=t[lson].lc;
	if(t[lson].lazy)t[id].lc=!t[id].lc;
	t[id].rc=t[rson].rc;
	if(t[rson].lazy)t[id].rc=!t[id].rc;
	int lf=t[lson].rc,rf=t[rson].lc;
	if(t[lson].lazy)lf=!lf;
	if(t[rson].lazy)rf=!rf;
	t[id].sum=t[lson].sum+t[rson].sum-(lf==rf);
	cout<<" sum:"<<t[id].sum<<" lc:"<<t[id].l<<"="<<t[id].lc<<" rc:"<<t[id].r<<"="<<t[id].rc<<endl;
}
void buildtree(int id,int l,int r){
	t[id].l=l;
	t[id].r=r;
	t[id].lazy=0;
	t[id].lc=a[l];
	t[id].rc=a[r];
	if(l==r){
		t[id].sum=1;
		return;
	}
	int mid=(l+r)>>1;
	buildtree(lson,l,mid);
	buildtree(rson,mid+1,r);
	update(id);
}
void change(int id,int l,int r){
	/*F*/cout<<"to: "<<id<<' '<<t[id].l<<"->"<<l<<' '<<t[id].r<<"->"<<r<<endl;
	if(t[id].l>=l&&t[id].r<=r){
		t[id].lazy=!(t[id].lazy);
		/*F*/cout<<"changed"<<endl;
		return;
	}
	pushdown(id);
	if(t[lson].r>=r)change(lson,l,r);
	else if(t[rson].l<=l)change(rson,l,r);
	else{
		change(lson,l,t[lson].r);
		change(rson,t[rson].l,r);
	}
	update(id);
}
int query(int id,int l,int r){
	/*F*/cout<<"to: "<<id<<' '<<t[id].l<<"->"<<l<<' '<<t[id].r<<"->"<<r<<endl;
	if(t[id].l>=l&&t[id].r<=r){
		/*F*/cout<<"checked"<<endl;
		return t[id].sum;
	}
	pushdown(id);
	if(t[lson].r>=r)return query(lson,l,r);
	else if(t[rson].l<=l)return query(rson,l,r);
	else{
		int lf=t[lson].rc,rf=t[rson].lc;
		if(t[lson].lazy)lf=!lf;
		if(t[rson].lazy)rf=!rf;
		return query(lson,l,t[lson].r)+query(rson,t[rson].l,r)-(rf==lf);
	}
}
int main(){
	ios::sync_with_stdio(false);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	buildtree(1,1,n);
	for(int i=1;i<=m;i++){
		op=read();x=read();y=read();
		if(op==1){
			change(1,x,y);
		}else{
			cout<<query(1,x,y)<<endl;
		}
	}
	return 0;
}
```

# Djacl. 线段树基础练习5
时间限制：4.0s   内存限制：512.0MB   代码提交间隔：5分钟(现在可以提交)  
试题来源：基础练习
### 问题描述
　　输入两个长为n的数列a[i],b[i]。维护m个操作，操作分3类：
　　（1）：对于其中连续一段执行：a[i]赋值为a[i]+b[i]
　　（2）：对于其中连续一段执行：b[i]赋值为a[i]+b[i]
　　（3）：对于其中连续一段求a[i]b[i]的和，mod 10301输出
### 输入格式
　　n m
　　a[1] b[1]
　　a[2] b[2]
　　...
　　a[n] b[n]
　　1 l r / 2 l r / 3 l r
### 输出格式
　　每个询问一个输出，mod 10301输出
### 样例输入
```
4 3
1 1
2 1
1 1
2 2
3 2 3
2 2 4
3 1 4
```
### 样例输出
```
3
17
```
### 数据规模和约定
　　n,m<=100000, a[i] <=100000



Code:
```cpp
#include"iostream"
using namespace std;
#define N 1010
#define lson id<<1
#define rson id<<1|1
#define mod 10301
int a[N],b[N],n,m,op,x,y,k;
int base1[3][3]={
	{1,1,2},
	{0,1,0},
	{0,1,1}};
int base2[3][3]={
	{1,0,0},
	{1,1,2},
	{1,0,1}};
struct matrix{
	int v[3][3];
	int x,y;
}c1,c2;
struct node{
	int l,r;
	matrix sum,lazy;
}t[4*N];
ostream&operator<<(ostream&ous,matrix a){
	for(int i=0;i<a.x;i++){
		for(int j=0;j<a.y;j++){
			ous<<a.v[i][j]<<' ';
		}
		ous<<endl;
	}
	return ous;
}
bool check(matrix a){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if((i==j&&a.v[i][j]!=1)||(i!=j&&a.v[i][j]!=0))return 1;
		}
	}
	return 0;
}
void clear(matrix&a){
	for(int i=0;i<a.x;i++){
		for(int j=0;j<a.y;j++){
			if(i==j)a.v[i][j]=1;
			else a.v[i][j]=0;
		}
	}
}
matrix operator+(matrix a,matrix b){
	matrix c;
	if(a.x!=b.x||a.y!=b.y)return c;
	int x=a.x,y=a.y;
	c.x=x;
	c.y=y;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			c.v[i][j]=(a.v[i][j]+b.v[i][j])%mod;
		}
	}
	return c;
}
matrix operator*(matrix a,matrix b){
	matrix c;
	if(a.y!=b.x)return c;
	int x=a.x,y=b.y,z=a.y;
	c.x=x;
	c.y=y;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			c.v[i][j]=0;
			for(int k=0;k<z;k++){
				c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j]+mod)%mod;
			}
		}
	}
	return c;
}
matrix&operator*=(matrix&a,matrix n){
	a=a*n;
	return a;
}
void update(int id){
	t[id].sum=(t[lson].lazy*t[lson].sum)+(t[rson].lazy*t[rson].sum);
}
void pushdown(int id){
	if(check(t[id].lazy)){
		t[lson].lazy=t[id].lazy*t[lson].lazy;
		t[rson].lazy=t[id].lazy*t[rson].lazy;
		t[id].sum=t[id].lazy*t[id].sum;
		clear(t[id].lazy);
	}
}
void buildtree(int id,int l,int r){
	t[id].l=l;
	t[id].r=r;
	t[id].lazy.x=t[id].lazy.y=3;
	clear(t[id].lazy);
	t[id].sum.x=3;
	t[id].sum.y=1;
	if(l==r){
		t[id].sum.v[0][0]=(a[l]*a[l])%mod;
		t[id].sum.v[1][0]=(b[l]*b[l])%mod;
		t[id].sum.v[2][0]=(a[l]*b[l])%mod;
		return;
	}
	int mid=(l+r)>>1;
	buildtree(lson,l,mid);
	buildtree(rson,mid+1,r);
	update(id);
}
void change1(int id,int l,int r){
	if(t[id].l>=l&&t[id].r<=r){
		t[id].lazy=c1*t[id].lazy;
		return;
	}
	pushdown(id);
	if(t[lson].r>=r)change1(lson,l,r);
	else if(t[rson].l<=l)change1(rson,l,r);
	else{
		change1(lson,l,t[lson].r);
		change1(rson,t[rson].l,r);
	}
	update(id);
}
void change2(int id,int l,int r){
	if(t[id].l>=l&&t[id].r<=r){
		t[id].lazy=c2*t[id].lazy;
		return;
	}
	pushdown(id);
	if(t[lson].r>=r)change2(lson,l,r);
	else if(t[rson].l<=l)change2(rson,l,r);
	else{
		change2(lson,l,t[lson].r);
		change2(rson,t[rson].l,r);
	}
	update(id);
}
matrix query(int id,int l,int r){
	if(t[id].l>=l&&t[id].r<=r){
		return t[id].lazy*t[id].sum;
	}
	pushdown(id);
	if(t[lson].r>=r)return query(lson,l,r);
	else if(t[rson].l<=l)return query(rson,l,r);
	else{
		return query(lson,l,t[lson].r)+query(rson,t[rson].l,r);
	}
}
void init(){
	for(int i=0;i<c1.x;i++){
		for(int j=0;j<c1.y;j++){
			c1.v[i][j]=base1[i][j];
		}
	}
	for(int i=0;i<c2.x;i++){
		for(int j=0;j<c2.y;j++){
			c2.v[i][j]=base2[i][j];
		}
	}
}
int main(){
	freopen("testdata.in","r",stdin);
	freopen("testdata.out","w",stdout);
	c1.x=c1.y=c2.x=c2.y=3;
	init();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		a[i]%=mod;
		b[i]%=mod;
	}
	buildtree(1,1,n);
	for(int i=1;i<=m;i++){
		cin>>op>>x>>y;
		if(op==1)change1(1,x,y);
		else if(op==2)change2(1,x,y);
		else cout<<query(1,x,y).v[2][0]%mod<<endl;
	}
	return 0;
}

```