#include "bits/stdc++.h"
using namespace std;
int n,m,cx,cy,f[100010];
string ch;
bool lev[110][110];
int pos(int x,int y){
    return x*m+y;
}
int getf(int x){
    return f[x]==x?x:f[x]=getf(f[x]);
}
void merge(int x,int y){
    int fx=getf(x),fy=getf(y);
    if(fx!=fy)f[fy]=fx;
}
int check(int t){
    for(int i=t;i<n;i++){
        for(int j=0;j<m;j++){
            if(lev[i-t][j]&&lev[i][j])merge(pos(i,j),pos(i-t,j));
        }
    }
    return getf(pos(cx,cy))==getf(pos(n,-1));
}
int main(){
    // freopen("ArcadeManao.in","r",stdin);
    // freopen("ArcadeManao.out","w",stdout);
    cin>>n;
    getline(cin,ch);
    for(int i=0;i<n;i++){
        getline(cin,ch);
        m=ch.size();
        for(int j=0;j<m;j++){
            if(ch[j]=='X')lev[i][j]=1;
            else lev[i][j]=0;
        }
    }
    cin>>cx>>cy;
    cx--;cy--;
    lev[cx][cy]=1;
    for(int i=0;i<n*m;i++)f[i]=i;
    for(int i=0;i<n;i++){
        for(int j=1;j<m-1;j++){
            if(lev[i][j]){
                if(lev[i][j-1])merge(pos(i,j),pos(i,j-1));
                if(lev[i][j+1])merge(pos(i,j),pos(i,j+1));
            }
        }
    }
    if(getf(pos(cx,cy))==getf(pos(n,-1)))cout<<0<<endl;
    else{
        for(int i=1;i<=n;i++){
            if(check(i)){
                cout<<i<<endl;
                return 0;
            }
        }
        cout<<n<<endl;
    }
    return 0;
}