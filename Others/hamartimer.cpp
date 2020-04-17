#include "bits/stdc++.h"
#include "windows.h"
using namespace std;
int main(){
	int cnt=0;
    freopen("Passwords.txt","w",stdout);
    cout<<"Passwords.exe"<<endl;
    cout<<"Version:1.1.0"<<endl<<endl;
	while(true){
		cnt++;
		srand(time(NULL)*rand()*(rand()%10)+cnt);
		for(int i=1;i<=rand()%15+20;i++){
			if(rand()%5000==0)cout<<"schtonn",i+=7;
			if(rand()%30==0)cout<<'-',i++;
			if(rand()%2){
				cout<<rand()%10;
			}else{
				if(rand()%2){
					cout<<(char)('a'+(rand()%26));
				}else{
					cout<<(char)('A'+(rand()%26));
				}
			}
		}
		cout<<endl;
		if(rand()%100==0&&cnt>=200)break;
	}
    cout<<"Total Password Summoned: "<<cnt<<endl;
	system("notepad passwords.txt");
	return 0;
}