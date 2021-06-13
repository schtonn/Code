#include "bits/stdc++.h"
using namespace std;
const int N=1000010;
struct node{
    int u,v,c;
}e[N];
int tot,h[N];
int n,mp[510][510],f[N],siz[N];
int m2g(int i,int j){
	return (i-1)*n+j;
}
void ade(int i,int j,int k,int l){
    e[tot].u=m2g(i,j);
    e[tot].v=m2g(k,l);
    e[tot].c=abs(mp[i][j]-mp[k][l]);
    tot++;
}
bool cmp(node a,node b){
    return a.c<b.c;
}
int getf(int x){
    return x==f[x]?x:f[x]=getf(f[x]);
}
int main(){
    cin>>n;
    int lim=(n*n+1)/2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>1)ade(i,j,i-1,j);
            if(j>1)ade(i,j,i,j-1);
        }
    }
    for(int i=1;i<=n*n;i++){
        f[i]=i;
        siz[i]=1;
    }
    sort(e,e+tot,cmp);
    for(int i=0;i<tot;i++){
        int fu=getf(e[i].u),fv=getf(e[i].v);
        if(fu!=fv){
            f[fu]=fv;
            siz[fv]+=siz[fu];
            if(siz[fv]>=lim){
                cout<<e[i].c<<endl;
                return 0;
            }
        }
    }
    return 0;
}