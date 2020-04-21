#include "bits/stdc++.h"
using namespace std;
vector <string>clip(200);
int n,T;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>clip[i];
	}
	cin>>T;
	int x=n;
	int y=clip[0].size();
	int s=-(y-1);
	int t=(x-1);
	long long cnt[200];
	for(int i=0;i<200;i++)
		cnt[i]=0;
	long long count_black=0;
	for(int i=s;i<=0;i++){
		int j=0;
		int k=j-i;
		bool fs=false;
		int ft=-1;
		for(j=0;j<x;j++){
			k=j-i;
			if(k>=y)break;
			if(clip[j][k]=='B'){
				if(fs==false){
					ft=j+T;
					cnt[i+y]+=T;
				}
				fs=true;
				cnt[i+y]+=min((j+T)-ft,T);
				ft=j+T;
			}
		}
	}
	for(int i=1;i<=t;i++){
		int j=0;
		int k=j+i;
		bool fs=false;
		int ft=-1;
		for(j=0;j<y;j++){
			k=j+i;
			if(k>=x)
				break;
			if(clip[k][j]=='B'){
				if(fs==false){
					ft=k+T;
					cnt[i+y]+=T;
				}
				fs=true;
				cnt[i+y]+=min((k+T)-ft,T);
				ft=k+T;
			}
		}
	}
	for(int i=0;i<200;i++){
		count_black+=cnt[i];
	}
	cout<<count_black<<endl;
	return 0;
}