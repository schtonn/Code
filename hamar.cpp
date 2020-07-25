#include "bits/stdc++.h"
using namespace std;
int n,m,cx,cy,f[100010];
string lev[110];
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
            if(lev[i-t][j]=='X'&&lev[i][j]=='X')merge(pos(i,j),pos(i-t,j));
        }
    }
    return getf(pos(cx,cy))==getf(pos(n,-1));
}
int main(){
	// freopen("AcradeManao.in","r",stdin);
	// freopen("ArcadeManao.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>lev[i];
    }
    m=lev[0].size();
    cin>>cx>>cy;
    cx--;cy--;
    for(int i=0;i<n*m;i++)f[i]=i;
    for(int i=0;i<n;i++){
        for(int j=1;j<m-1;j++){
            if(lev[i][j]=='X'){
                if(lev[i][j-1]=='X')merge(pos(i,j),pos(i,j-1));
                if(lev[i][j+1]=='X')merge(pos(i,j),pos(i,j+1));
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
/*
#include <bits/stdc++.h>
using namespace std;
const int N=51;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,-1,1};
int n,m,t,w,b[N][N];
int f[N*N];

template<class T> void checkmin(T &a,const T &b) { if (b<a) a=b; }
template<class T> void checkmax(T &a,const T &b) { if (b>a) a=b; }

class ArcadeManao {
public:
    int shortestLadder( vector <string> level, int coinRow, int coinColumn ) ;
};

int gf(int x){ return f[x]==x?x:f[x]=gf(f[x]); }

void unio(int q,int w,int e,int r){
    int x=q*m+w,y=e*m+r,fx=gf(x),fy=gf(y);
    if (fx!=fy) f[fx]=fy;
}

int pd(int l,int tx,int ty,vector<string> a){
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
      if (a[i][j]=='X'&&i-l>=0&&a[i-l][j]=='X') unio(i,j,i-l,j);
    return gf(tx*m+ty)==gf(n*m-1);
}

int ArcadeManao::shortestLadder(vector <string> a, int tx, int ty) {
    n=a.size();m=a[0].size();
    for(int i=0;i<n*m;i++) f[i]=i;
    tx--;ty--;
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
      if (a[i][j]=='X'){
          if (j>0&&a[i][j-1]=='X') unio(i,j,i,j-1);
          if (j<m-1&&a[i][j+1]=='X') unio(i,j,i,j+1);
      }
    if (gf(tx*m+ty)==gf(n*m-1)) return 0;
    for(int i=1;i<=n;i++)
     if (pd(i,tx,ty,a)) return i;
    return n;
}
*/