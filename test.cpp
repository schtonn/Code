#include"iostream"
using namespace std;
int t[1034][1034],n,m,op,l,r,x,y,c;
int lowbit(int x){return x&-x;}
void add(int i,int j,int c){
	int x=i,y=j;
	while(x<n){
		y=j;
		while(y<n){
			t[x][y]+=c;
			y+=lowbit(y);
		}
		x+=lowbit(x);
	}
}
int query(int i,int j){
	int sum=0,x=i,y=j;
	while(x>0){
		y=j;
		while(y>0){
			sum+=t[x][y];
			y-=lowbit(y);
		}
		x-=lowbit(x);
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
			add(x,y,c);
		}
		else if(op==2){
			cin>>l>>x>>r>>y;
			cout<<query(r,y)-query(r,x-1)-query(l-1,y)+query(l-1,x-1)<<endl;
		}else{
			break;
		}
	}
	return 0;
}