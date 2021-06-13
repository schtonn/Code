#include "bits/stdc++.h"
using namespace std;
#define N 1000010
int n,m,s,c[N],color[N],pre[N],ans[N],p[N];
struct node{
    int L,R,id;
}q[N];
bool cmd(node a,node b){
    return a.R<b.R;
}
inline int lowbit(int x){return (x&(-x));}
inline void add(int x,int d){
    if(!x)return;
    s+=d;
    while(x<=n){
        c[x]+=d;
        x+=lowbit(x);
    }
}
inline int sum(int x){
    int res=0;
    while(x>=1){
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        pre[i]=color[p[i]];
        color[p[i]]=i;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>q[i].L>>q[i].R;
        q[i].id=i;
    }
    sort(q+1,q+1+m,cmd);
    for(int i=1,j=1;i<=m;i++){
        for(;j<=q[i].R;j++){
            add(pre[j],-1);
            add(j,1);
        }
        ans[q[i].id]=s-sum(q[i].L-1);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
/*
S H H C R H R H L R L R E R H
H S S C C C R C A C H H C R E
H S R H H H H H L L C C H E L
S C C A I I H H T L A C E E L
R C R I I A M A A A L A E C E
S S R A L M M M A T A A C E E
S C R A R R T K K E E D A L E
I D D R R I E T T K K L D K E
U S D A I M M M T T T D K L L
U S D A D M D M U D U L D K E
I I S U D I D D T U D U U K L
U S U D U M I T M T U U K L K
S I I F U I M M T F F U F F K
S S S K I F M F F T T F K F F
U K F I F M K F T K T F E F E
*/