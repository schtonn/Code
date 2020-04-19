#include "bits/stdc++.h"
using namespace std;
int a[200],b[200];
int main(){
	freopen("testdata.in","w",stdout);
	srand(time(NULL));
	cout<<10<<' '<<100<<endl;
	for(int i=1;i<=10;i++){
		a[i]=rand()%9+1;
	}
	for(int i=1;i<=10;i++){
		b[i]=rand()%9+1;
	}
	for(int i=1;i<=10;i++){
		cout<<a[i]<<' '<<b[i]<<endl;
	}
	for(int i=1;i<=100;i++){
		int op=rand()%3+1;
		int l=rand()%9+1,r=rand()%9+1;
		if(l>r)swap(l,r);
		cout<<op<<' '<<l<<' '<<r<<endl;
	}
	return 0;
}