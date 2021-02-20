#include "bits/stdc++.h"
using namespace std;
#define N 100
#define M 6400
int x,y,f[N][N],ansf[N][N];
int a[M][100],ca[M],con[M],ans[M];
int n,m;//n=number of equation, m=number of unknown
struct loc{
    int x,y;
}p[M];
int c[N][N];
void clear(int i,int j){
    a[i][j]=0;
    swap(a[i][j],a[i][ca[i]]);
    ca[i]--;
}
void rnd(int u,int v){
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int X=u+i,Y=v+j;
            if(X<=x&&Y<=y&&X>0&&Y>0){
                if(!f[X][Y]){
                    a[n][++ca[n]]=c[X][Y];
                }
            }
        }
    }
}
void label(){
    for(int i=1;i<=x;i++){
        for(int j=1;j<=x;j++){
            if(!f[i][j]){
                m++;
                p[m].x=i;
                p[m].y=j;
                c[i][j]=m;
            }
        }
    }
}
void print(){
    cout<<"cr:";
    for(int i=1;i<=m;i++){
        cout<<i<<"=("<<p[i].x<<','<<p[i].y<<") ";
    }
    cout<<endl;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=x;j++){
            cout<<"("<<i<<","<<j<<")="<<c[i][j]<<' ';
        }
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=ca[i];j++){
            cout<<a[i][j]<<' ';
        }
        cout<<con[i]<<endl;
    }
}
void init(){
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=x;j++){
            cin>>f[i][j];
        }
    }
    label();
    for(int i=1;i<=x;i++){
        for(int j=1;j<=x;j++){
            if(f[i][j]){
                n++;
                rnd(i,j);
            }
        }
    }
    int flag=0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=x;j++){
            if(f[i][j])con[++flag]=f[i][j];
        }
    }
}
void xrow(int u,int v){
    for(int i=1;i<=ca[u];i++){
        int flag=0;
        for(int j=1;j<=ca[v];j++){
            if(a[u][i]==a[v][j]){
                flag=j;
                break;
            }
        }
        if(flag){
            clear(v,flag);
        }else{
            a[v][ca[v]++]=a[u][i];
        }
    }
    con[v]^=con[u];
}
void srow(int u,int v){
    for(int i=1;i<=max(ca[u],ca[v]);i++){
        swap(a[u][i],a[v][i]);
    }
    swap(con[u],con[v]);
    swap(ca[u],ca[v]);
}
bool is(int u,int v){
    for(int i=1;i<=ca[u];i++){
        if(a[u][i]==v)return true;
    }
    return false;
}
void work(){
    for(int i=1;i<=n;i++){
        int r=i;
        if(!is(i,r)){
            for(int j=i+1;j<=m;j++){
                if(is(j,i)){
                    r=j;
                    break;
                }
            }
            srow(i,r);
        }
        for(int j=i+1;j<=n;j++){
            if(is(j,i))xrow(i,j);
        }
    }
}
void solute(){
    for(int i=n;i>0;i--){
        start:
        //print();
        int flag=0,pos;
        for(int j=1;j<=m;j++)if(is(i,j)){
            flag++;
            pos=j;
        }
        if(flag==0)continue;
        if(flag==1)ans[pos]=con[i];
        for(int j=1;j<i;j++){
            if(is(j,pos))xrow(i,j);
        }
        for(int j=1;j<=ca[i];j++){
            if(a[i][j]==pos)clear(i,j);
        }
        if(flag!=1)goto start;
    }
}
int main(){
    init();
    work();
    print();
    solute();
    for(int i=1;i<=m;i++){
        ansf[p[i].x][p[i].y]=ans[i];
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=x;j++){
            cout<<ansf[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}