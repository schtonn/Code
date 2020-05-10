#include "bits/stdc++.h"
using namespace std;
char x[100],y[100],z[100];
int len;
int main(){
    cin>>x>>y;
	len=strlen(x);
    for(int i=0;i<=len;i++){
        // cout<<i<<endl;
        for(int j=0;j<i;j++){
            z[j]=x[j];
        }
        // cout<<x<<endl<<y<<endl<<z<<endl;
        for(int j=i;j<len+i;j++){
            z[j]=x[j-i];
        }
        // cout<<x<<endl<<y<<endl<<z<<endl;
        for(int j=len+i;j<len*2;j++){
            z[j]=x[j-len];
        }
        // cout<<x<<endl<<y<<endl<<z<<endl;
		bool fleg=1;
		for(int j=0;j<len*2;j++){
			if(z[i]!=y[i]){
				fleg=0;
				break;
			}
		}
		if(fleg==1){
			cout<<"Yes"<<endl;
			return 0;
		}
    }
	cout<<"No"<<endl;
    return 0;
}