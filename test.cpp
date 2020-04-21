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
	long long cnt_r[200];
	long long cnt_g[200];
	long long cnt_b[200];
	for(int i=0;i<200;i++)cnt_r[i]=cnt_g[i]=cnt_b[i]=0;
	long long count_red=0;
	long long count_green=0;
	long long count_blue=0;
	for(int i=s;i<=0;i++){
		int j=0;
		int k=j-i;
		bool fs=false;
		int ft=-1;
		for(j=0;j<x;j++){
			k=j-i;
			if(k>=y)break;
			if(clip[j][k]=='R'){
				if(fs==false){
					ft=j+T;
					cnt_r[i+y]+=T;
				}
				fs=true;
				cnt_r[i+y]+=min((j+T)-ft,T);
				ft=j+T;
			}
			if(clip[j][k]=='G'){
				if(fs==false){
					ft=j+T;
					cnt_g[i+y]+=T;
				}
				fs=true;
				cnt_g[i+y]+=min((j+T)-ft,T);
				ft=j+T;
			}
			if(clip[j][k]=='B'){
				if(fs==false){
					ft=j+T;
					cnt_b[i+y]+=T;
				}
				fs=true;
				cnt_b[i+y]+=min((j+T)-ft,T);
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
			if(clip[k][j]=='R'){
				if(fs==false){
					ft=k+T;
					cnt_r[i+y]+=T;
				}
				fs=true;
				cnt_r[i+y]+=min((k+T)-ft,T);
				ft=k+T;
			}
			if(clip[k][j]=='G'){
				if(fs==false){
					ft=k+T;
					cnt_g[i+y]+=T;
				}
				fs=true;
				cnt_g[i+y]+=min((k+T)-ft,T);
				ft=k+T;
			}
			if(clip[k][j]=='B'){
				if(fs==false){
					ft=k+T;
					cnt_b[i+y]+=T;
				}
				fs=true;
				cnt_b[i+y]+=min((k+T)-ft,T);
				ft=k+T;
			}
		}
	}
	for(int i=0;i<200;i++){
		count_red+=cnt_r[i];
	}
	for(int i=0;i<200;i++){
		count_green+=cnt_g[i];
	}
	for(int i=0;i<200;i++){
		count_blue+=cnt_b[i];
	}
	cout<<count_red<<' '<<count_green<<' '<<count_blue<<endl;
	return 0;
}