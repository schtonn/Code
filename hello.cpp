#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int n,m,p,f[21],con,w[200],ans;
string name[100],say[200];
string day[10]={"","Today is Sunday.","Today is Monday.","Today is Tuesday.","Today is Wednesday.","Today is Thursday.","Today is Friday.","Today is Saturday.",};
void set(int u,int k){
    if(f[u]!=-1&&f[u]!=k)con=1;
    else f[u]=k;
}
int main(){
    cin>>m>>n>>p;
    for(int i=1;i<=m;i++)
        cin>>name[i];
    for(int i=1;i<=p;i++){
        string nm;
        cin>>nm;
        nm.erase(nm.end()-1);
        for(int j=1;j<=m;j++)
        if(name[j]==nm)w[i]=j;
        getline(cin,say[i]);
        say[i].erase(say[i].begin());
    }
    for(int a=1;a<=7;a++){
        for(int b=1;b<=m;b++){
            con=0;
            memset(f,-1,sizeof(f));
            for(int i=1;i<=p;i++){
                int u=w[i];
                if(say[i]=="I am guilty.")set(u,b==u);
                if(say[i]=="I am not guilty.")set(u,b!=u);
                for(int j=1;j<=7;j++)
                if(say[i]==day[j])set(u,j==a);
                for(int j=1;j<=m;j++){
                    if(say[i]==name[j]+" is guilty.")set(u,j==b);
                    if(say[i]==name[j]+" is not guilty.")set(u,j!=b);
                }
            }
            int fak=0,neu=0;
            for(int i=1;i<=m;i++){
                if(f[i]==1)fak++;
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
    else cout<<name[ans];
    return 0;
}