#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=3005;
int n,m,q,e;
int bfn[maxn],fa[maxn],t[maxn],ok[maxn];
int delp[maxn][maxn],delf[maxn][maxn];//delp[y][x]: del x 1 to y ; delf[y][x]: del fa[x] 1 to y
vector<int>g[maxn],rg[maxn],d[maxn];
inline int cmp(int x,int y){
    return d[x].size()<d[y].size();
}
void getdelp(int x,int p){
    if(x==p)
        return ;
    delp[x][p]=1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(delp[y][p]==0)
            getdelp(y,p);
    }
}
void getdelf(int x,int p){
    if(x==fa[p])
        return ;
    delf[x][p]=1;
    for(int i=0;i<rg[x].size();i++){
        int y=rg[x][i];
        if(delf[y][p]==0)
            getdelf(y,p);
    }
}
void read(int &x){
    x=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        x=x*10+c-48;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        int x,y;
        read(x),read(y);
        g[x].push_back(y),rg[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        getdelp(1,i);
        for(int j=1;j<=n;j++)
            if(delp[j][i]==0)
                d[j].push_back(i);
    }
    for(int i=2;i<=n;i++)
        for(int j=0;j<d[i].size();j++)
            if(d[d[i][j]].size()==d[i].size()-1){
                fa[i]=d[i][j];
                break;
            }
    for(int i=1;i<=n;i++)
        bfn[i]=i;
    sort(bfn+1,bfn+1+n,cmp);
    for(int i=2;i<=n;i++)
        getdelf(i,i);
    for(int i=1;i<=q;i++){
        int x,y,res=0;
        read(x),read(y);
        for(int j=1;j<=n;j++)
            if(fa[j]!=1&&fa[j]!=x&&delp[x][fa[j]]&&delf[y][j])
                ok[j]=1;
        for(int j=2;j<=n;j++){
            ok[bfn[j]]|=ok[fa[bfn[j]]];
            res+=ok[bfn[j]];
        }
        for(int j=1;j<=n;j++)
            ok[j]=0;
        printf("%d\n",res);
    }
    return 0;
}