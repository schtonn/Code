#include "iostream"
using namespace std;
int n,a,b,c,ac,bc,cc,minn=-1,mint=-1;
int main(){
//	freopen("order.in","r",stdin);
//	freopen("order.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n/7;i++){
		for(int j=0;j<=(n-(i*7))/4;j++){
			if((n-(i*7)-(j*4))%3!=0)continue;
			int k=(n-(i*7)-(j*4))/3;
			if(min(k,min(j,i))>minn){
				a=i;b=j;c=k;
				minn=min(k,min(j,i));
				mint=k+j+i;
				continue;
			}
			if(min(k,min(j,i))==minn&&k+j+i>mint){
				a=i;b=j;c=k;
				mint=k+j+i;
				continue;
			}
		}
	}
	if(mint==-1){
		cout<<-1<<endl;
	}else{
		cout<<a<<' '<<b<<' '<<c<<endl;
	}
	system("pause");
	return 0;
}