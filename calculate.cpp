#include "bits/stdc++.h"
using namespace std;
char x[100],y[100],z[100];
int main(){
    cin>>x>>y;
    for(int i=0;i<=strlen(x);i++){
        // cout<<i<<endl;
        for(int j=0;j<i;j++){
            z[j]=x[j];
        }
        // cout<<x<<endl<<y<<endl<<z<<endl;
        for(int j=i;j<strlen(x)+i;j++){
            z[j]=x[j-i];
        }
        // cout<<x<<endl<<y<<endl<<z<<endl;
        for(int j=strlen(x)+i;j<strlen(x)*2;j++){
            z[j]=x[j-strlen(x)];
        }
        // cout<<x<<endl<<y<<endl<<z<<endl;
    }
    system("pause");
    return 0;
}