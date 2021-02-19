#include "bits/stdc++.h"
using namespace std;
#define N 100
#define M 6400
int x,y,f[N][N],ansf[N][N];
int a[M][9],ca[M],con[M],ans[M];
int n,m;//n=number of equation, m=number of unknown
struct loc{
    int x,y;
}p[M];
int c[N][N];
void rnd(int u,int v){
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int X=u+i,Y=v+j;
            if(X<x&&Y<y&&X>-1&&Y>-1){
                if(!f[X][Y]){
                    a[n][ca[n]++]=c[X][Y];
                }
            }
        }
    }
}
void label(){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            c[i][j]=i*x+j;
            p[c[i][j]].x=i;
            p[c[i][j]].y=j;
        }
    }
}
void print(){
    cout<<"cr:";
    for(int i=0;i<m;i++){
        cout<<i<<"=("<<p[i].x<<','<<p[i].y<<") ";
    }
    cout<<endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<"("<<i<<","<<j<<")="<<c[i][j]<<' ';
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"("<<p[j].x<<","<<p[j].y<<")";
            cout<<a[i][j]<<' ';
        }
        cout<<a[i][m]<<endl;
    }
}
void del(int u){
    for(int i=u;i<m;i++){
        p[i].x=p[i+1].x;
        p[i].y=p[i+1].y;
    }
    m--;
    for(int i=0;i<m;i++){
        c[p[i].x][p[i].y]=i;
    }
}
void init(){
    cin>>x>>y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>f[i][j];
        }
    }
    label();
    m=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(f[i][j]){
                rnd(i,j);
                n++;
            }
            m++;
        }
    }
    for(int u=0;u<m;u++){
        if(f[p[u].x][p[u].y]){
            del(u);
            u--;
        }
    }
    int flag=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(f[i][j])con[flag++]=f[i][j];
        }
    }
}
void xrow(int u,int v){
    for(int i=0;i<ca[u];i++){
        for(int j=0;j<ca[v];j++){
            if(a[u][i]==a[v][j]){
                a[v][j]=0;
                swap(a[v][j],a[v][ca[v]]);
                ca[v]--;
            }
        }
    }
    con[v]^=con[u];
}
void srow(int u,int v){
    for(int i=0;i<=max(ca[u],ca[v]);i++){
        swap(a[u][i],a[v][i]);
    }
}
bool is(int u,int v){
    for(int i=0;i<ca[u];i++){
        if(a[u][i]==v)return true;
    }
    return false;
}
void work(){
    for(int i=0;i<n;i++){
        int r=i;
        if(!is(i,r)){
            for(int j=i+1;j<m;j++){
                if(is(j,i)){
                    r=j;
                    break;
                }
            }
            srow(i,r);
        }
        for(int j=i+1;j<n;j++){
            if(is(j,i))xrow(i,j);
        }
    }
}
void solute(){
    for(int i=n-1;i>=0;i--){
        start:
        //print();
        int flag=0,pos;
        for(int j=0;j<m;j++)if(is(i,j)){
            flag++;
            pos=j;
        }
        if(flag==0)continue;
        if(flag==1)ans[pos]=con[i];
        for(int j=0;j<i;j++){
            if(is(j,pos))xrow(i,j);
        }
        for(int j=0;j<ca[i];j++){
            if(a[i][j]==pos){
                a[i][j]=0;
                ca[i]--;
                swap(a[i][j],a[i][ca[i]]);
            }
        }
        if(flag!=1)goto start;
    }
}
int main(){
    init();
    print();
    work();
    print();
    solute();
    for(int i=0;i<m;i++){
        ansf[p[i].x][p[i].y]=ans[i];
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<ansf[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}