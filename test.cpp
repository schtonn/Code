#include"iostream"
using namespace std;
int t[1034][1034],n,m,op,l,r,x,y,c;
int lowbit(int x){return x&-x;}
void add(int i,int j,int x){
	while(i<n){
		while(j<n){
			t[i][j]+=x;
			j+=lowbit(j);
		}
		i+=lowbit(i);
	}
}
int query(int i,int j){
	int sum=0;
	while(i){
		while(j){
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
			add(x,y,c);
		}
		else if(op==2){
			cin>>l>>x>>r>>y;
			cout<<query(r,y)-query(r,x)-query(l,y)+query(l,x)<<endl;
		}else{
			break;
		}
	}
	return 0;
}