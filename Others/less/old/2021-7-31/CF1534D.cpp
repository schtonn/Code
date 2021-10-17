#include "bits/stdc++.h"
using namespace std;
const int N=2010;
int n,tot,e[N][2],odd[N],check[N],vis[N];
void add(int u,int v){
    for(int i=1;i<=tot;i++)if((e[i][0]==u&&e[i][1]==v)||(e[i][1]==u&&e[i][0]==v))return;
    e[++tot][0]=u;
    e[tot][1]=v;
}
int main(){
    cin>>n;
    cout<<"? 1"<<endl;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a==1){
            add(1,i);
        }
        if(a&1){
            odd[i]=1;
            cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        if(cnt>=n-cnt){
            check[i]=!odd[i];
        }else{
            check[i]=odd[i];
        }
    }
    check[1]=0;
    for(int i=1;i<=n;i++){
        if(check[i]){
            cout<<"? "<<i<<endl;
            for(int j=1;j<=n;j++){
                int a;
                cin>>a;
                if(a==1){
                    add(i,j);
                }
            }
        }
        if(tot==n-1)break;
    }
    cout<<"!"<<endl;
    for(int i=1;i<n;i++){
        cout<<e[i][0]<<' '<<e[i][1]<<endl;
    }
    return 0;
}