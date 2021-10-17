## 卡常有效！！！卡常非常有效！！！！！
## 经常搞出奇怪的freopen！！！
## freopen很容易写错！！！！出了锅还找不出来！因为调的时候会跳过
## 线段树的数据范围要*4！
### 问题描述
　　在大学期间，经常需要租借教室。大到院系举办活动，小到学习小组自习讨论，都需要向学校申请借教室。教室的大小功能不同，借教室人的身份不同，借教室的手续也不一样。

　　面对海量租借教室的信息，我们自然希望编程解决这个问题。

　　我们需要处理接下来 n天的借教室信息，其中第 天学校有 $r_i$个教室可供租借。共有 m份订单，每份订单用三个正整数描述，分别为$d_j s_j t_j$ ，表示某租借者需要从第$s_j$ 天到第$t_j$ 天租借教室（包括第$s_j$ 天和第$t_j$ 天），每天需要租借 $d_j$ 个教室。

　　我们假定，租借者对教室的大小、地点没有要求。即对于每份订单，我们只需要每天提供 d_j 个教室，而它们具体是哪些教室，每天是否是相同的教室则不用考虑。

　　借教室的原则是先到先得，也就是说我们要按照订单的先后顺序依次为每份订单分配教室。如果在分配的过程中遇到一份订单无法完全满足，则需要停止教室的分配，通知当前申请人修改订单。这里的无法满足指从第 s_j 天到第 t_j 天中有至少一天剩余的教室数量不足 d_j 个。

　　现在我们需要知道，是否会有订单无法完全满足。如果有，需要通知哪一个申请人修改订单。
### 输入格式
　　第一行包含两个正整数n,m ，表示天数和订单的数量。

　　第二行包含n 个正整数，其中第 i 个数为$r_i$ ，表示第 天可用于租借的教室数量。

　　接下来有m 行，每行包含三个正整数 $f_j$,$s_j$,$t_j$，表示租借的数量，租借开始、结束分别在第几天。

　　每行相邻的两个数之间均用一个空格隔开。天数与订单均用从1 开始的整数编号。
### 输出格式
　　如果所有订单均可满足，则输出只有一行，包含一个整数0。否则（订单无法完全满足）输出两行，第一行输出一个负整数-1，第二行输出需要修改订单的申请人编号。
### 样例输入
```
4 3
2 5 4 3
2 1 3
3 2 4
4 2 4
```
### 样例输出
```
-1
2
```
### 输入输出样例说明
　　第1份订单满足后，4天剩余的教室数分别为0，3，2，3。第2份订单要求第2天到第4天每天提供3个教室，而第3天剩余的教室数为2，因此无法满足。分配停止，通知第2个申请人修改订单。
### 数据规模和约定
```
　　对于10%的数据，有 1<= n,m<=10 ；
　　对于30%的数据，有 1<=n, m<=1000；
　　对于70%的数据，有 1<=n,m<=10^5；
　　对于100%的数据，有 1<=n,m<=10^6。
```
```cpp
#include"iostream"
using namespace std;
#define N 1000010
#define lson id<<1
#define rson id<<1|1
long long a[N],n,m,op,x,y,k;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node{
	long long l,r,sum,lazy;
}t[4*N];
inline void update(long long id){
	t[id].sum=min(t[lson].sum+t[lson].lazy,
		t[rson].sum+t[rson].lazy);
}
inline void pushdown(long long id){
	if(t[id].lazy){
		t[lson].lazy+=t[id].lazy;
		t[rson].lazy+=t[id].lazy;
		t[id].sum+=t[id].lazy;
		t[id].lazy=0;
	}
}
inline void buildtree(long long id,long long l,long long r){
	t[id].l=l;
	t[id].r=r;
	t[id].lazy=0;
	if(l==r){
		t[id].sum=a[l];
		return;
	}
	long long mid=(l+r)>>1;
	buildtree(lson,l,mid);
	buildtree(rson,mid+1,r);
	update(id);
}
inline void change(long long id,long long l,long long r,long long c){
	if(t[id].l>=l&&t[id].r<=r){
		t[id].lazy+=c;
		return;
	}
	pushdown(id);
	if(t[lson].r>=r)change(lson,l,r,c);
	else if(t[rson].l<=l)change(rson,l,r,c);
	else{
		change(lson,l,t[lson].r,c);
		change(rson,t[rson].l,r,c);
	}
	update(id);
}
inline long long query(long long id,long long l,long long r){
	if(t[id].l>=l&&t[id].r<=r){
		return t[id].sum+t[id].lazy;
	}
	pushdown(id);
	if(t[lson].r>=r)return query(lson,l,r);
	else if(t[rson].l<=l)return query(rson,l,r);
	else{
		return min(query(lson,l,t[lson].r),query(rson,t[rson].l,r));
	}
	update(id);
}
int main(){
	freopen("classroom.in","r",stdin);
	freopen("classroom.out","w",stdout);
	ios::sync_with_stdio(false);
	n=read();m=read();
	for(long long i=1;i<=n;i++){
		a[i]=read();
	}
	buildtree(1,1,n);
	for(long long i=1;i<=m;i++){
		k=read();x=read();y=read();
		if(query(1,x,y)<k){
			op=i;
			break;
		}
		change(1,x,y,-k);
	}
	if(op)cout<<-1<<endl;
	cout<<op<<endl;
	return 0;
}
```