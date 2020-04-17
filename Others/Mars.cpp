#include "bits/stdc++.h"
using namespace std;
int n,m,bridge[1000010];
int brand(){
	return rand()<<16|rand();	
}
int main(){
	freopen("out.txt","w",stdout);
	srand(time(NULL));
	for(int i=1;i<=1000000;i++){
		bridge[brand()%1000]++;	
	}
	for(int i=0;i<1000;i++){
		cout<<bridge[i]<<endl;;	
	}
    return 0;
}
