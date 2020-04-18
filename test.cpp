#include"iostream"
using namespace std;
int t[1034][1034],n,m,op,l,r,x,y,c;
int lowbit(int x){return x&-x;}
void add(int x,int y,int c){
	int i=x,j=y;
	while(i<=n){
		j=y;
		while(j<=n){
			t[i][j]+=c;
			j+=lowbit(j);
		}
		i+=lowbit(i);
	}
}
int query(int x,int y){
	int sum=0,i=x,j=y;
	while(i>0){
		j=y;
		while(j>0){
			sum+=t[i][j];
			j-=lowbit(j);
		}
		i-=lowbit(i);
	}
	return sum;
}
int main(){
	while(true){
		cin>>op;
		if(op==0){
			cin>>n;
		}else if(op==1){
			cin>>x>>y>>c;
			add(x+1,y+1,c);
		}
		else if(op==2){
			cin>>l>>x>>r>>y;
			cout<<query(r+1,y+1)-query(r+1,x)-query(l,y+1)+query(l,x)<<endl;
		}else{
			break;
		}
	}
	return 0;
}