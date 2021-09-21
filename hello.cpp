#include "bits/stdc++.h"
using namespace std;
const int N=2e7+5;
int r,c,n,f[N],ans=0;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
bool a[3005][6005];
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
int id(int x,int y){
    return(x-1)*c*2+y;
}
bool ok(int&x,int&y){
    if(y==0)y=c*2;
    else if(y==c*2+1)y=1;
    return(x>0&&x<=r&&a[x][y]);
}
bool can(int x,int y){
    int x_=x,y_=y+c;
    for(int i=0;i<8;i++){
        int X=x+dx[i],Y=y+dy[i];
        if(!ok(X,Y))continue;
        for(int j=0;j<8;j++){
            int X_=x_+dx[j],Y_=y_+dy[j];
            if(!ok(X_,Y_))continue;
            if(find(id(X,Y))==find(id(X_,Y_))){return 0;}
        }
    }
    return 1;
}
void merge(int a,int b){
    int x=find(a),y=find(b);
    f[x]=y;
}
void del(int x,int y){
    int x_=x,y_=y+c;
    for(int i=0;i<8;i++){
        int X=x+dx[i],Y=y+dy[i];
        if(ok(X,Y))merge(id(x,y),id(X,Y));
        int X_=x_+dx[i],Y_=y_+dy[i];
        if(ok(X_,Y_))merge(id(x_,y_),id(X_,Y_));
    }
    a[x][y]=1;
    a[x_][y_]=1;
}
int main(){
    cin>>r>>c>>n;
    if(c==1){
        cout<<0<<endl;
        return 0;   
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c*2;j++){
            f[id(i,j)]=id(i,j);
        }
    }
    while(n--){
        int x,y;
        cin>>x>>y;
        if(can(x,y))del(x,y),ans++;
    }
    printf("%d\n",ans);
    return 0;
}