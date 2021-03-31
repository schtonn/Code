#include "bits/stdc++.h"
using namespace std;
int n,c[100010],w[100010],kkk[100010],ans[100010];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        c[i]%=100;
    }
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        kkk[i]=(100-c[i])*w[i];
    }
    priority_queue<int,int,less<int>>q;
    for(int i=1;i<=n;i++){
        if(!c[i]){
            continue;
        }
    }
    return 0;
}