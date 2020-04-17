#include "bits/stdc++.h"
using namespace std;
int main(){
	freopen("hamar.doc","w",stdout);
	srand(time(NULL));
	for(int i=1;i<=300;i++){
		int a=100,b=0;
		while(a-b>9){
			a=rand()%10+10;
			b=rand()%9+1;
		}
		cout<<a<<"-"<<b<<"="<<endl;
	}
	return 0;
}