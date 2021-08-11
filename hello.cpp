#include "bits/stdc++.h"
using namespace std;
const int N=100;
string nam[N],s[N];
string day[10]={"","Today is Sunday.","Today is Monday.","Today is Tuesday.","Today is Wednesday.","Today is Thursday.","Today is Friday.","Today is Saturday.",};
int n,m,p,f[N],con,w[N],ans;
void g(int u,int k){
    if(f[u]!=-1&&f[u]!=k)con=1;
    else f[u]=k;
}
int main(){
    cin>>m>>n>>p;
    for(int i=1;i<=m;i++)cin>>nam[i];
    for(int i=1;i<=p;i++){
        string say;
        cin>>say;
        say=say.substr(0,say.length()-1);
        for(int j=1;j<=m;j++)
        if(nam[j]==say)w[i]=j;
        getline(cin,s[i]);
        s[i].erase(s[i].begin());
    }
    for(int a=1;a<=7;a++){
        for(int b=1;b<=m;b++){
            con=0;
            memset(f,-1,sizeof(f));
            for(int i=1;i<=p;i++){
                int u=w[i];
                if(s[i]=="I am guilty.")g(u,b==u);
                if(s[i]=="I am not guilty.")g(u,b!=u);
                for(int j=1;j<=7;j++)
                if(s[i]==day[j])g(u,j==a);
                for(int j=1;j<=m;j++){
                    if(s[i]==nam[j]+" is guilty.")g(u,j==b);
                    if(s[i]==nam[j]+" is not guilty.")g(u,j!=b);
                }
            }
            int fak=0,neu=0;
            for(int i=1;i<=m;i++){
                if(f[i]==0)fak++;
                if(f[i]==-1)neu++;
            }
            if(!con&&fak<=n&&fak+neu>=n){
                if(ans&&ans!=b){
                    cout<<"Cannot Determine";
                    return 0;
                }else ans=b;
            }
        }
    }
    if(!ans)cout<<"Impossible";
    else cout<<nam[ans];
    return 0;
}