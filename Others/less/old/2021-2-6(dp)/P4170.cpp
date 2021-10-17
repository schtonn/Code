#include "bits/stdc++.h"
using namespace std;
const int inf=0x3f3f3f3f;
int n,f[100][100];
string a;
int main(){
    cin>>a;
    n=a.size(); 
    memset(f,inf,sizeof(f));
    for(int i=1;i<=n;i++){
        f[i][i]=1;
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if(a[i-1]==a[j-1]){
                f[i][j]=min(f[i+1][j],f[i][j-1]);
                continue;
            }
            for(int k=i;k<=j;k++){
                f[i][j]=min(f[i][k]+f[k+1][j],f[i][j]);
            }
        }
    }
    cout<<f[1][n];
    return 0;
} 