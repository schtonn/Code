#include "bits/stdc++.h"
using namespace std;
string a,b,c;
int f[1010][1010],step[1010][1010],al,bl,cl;
int main(){
    cin>>a>>b;
    al=a.length();
    bl=b.length();
    for(int i=1;i<=al;i++){
        f[i][0]=i;
    }
    for(int i=1;i<=bl;i++){
        f[0][i]=i;
    }
    for(int i=1;i<=al;i++){
        for(int j=1;j<=bl;j++){
            int A=f[i-1][j],B=f[i][j-1],C=f[i-1][j-1];
            f[i][j]=min(min(A,B),C)+1;
            if(a[i-1]==b[j-1]){
                f[i][j]=C;
            }
        }
    }
    cout<<f[al][bl]<<endl;
    return 0;
}