#include"iostream"
using namespace std;
int t[500010],n,m,op,x,y;
int lowbit(int x){return x&-x;}
void add(int i,int x){
	while(i<=n){
		t[i]+=x;
		i+=lowbit(i);
	}
}
int query(int i){
	int sum=0;
	while(i>0){
		sum+=t[i];
		i-=lowbit(i);
	}
	return sum;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>op;
		add(i,op);
	}
	for(int i=1;i<=m;i++){
		cin>>op>>x>>y;
		if(op==1)add(x,y);
		else cout<<query(y)-query(x-1)<<endl;
	}
	return 0;
}