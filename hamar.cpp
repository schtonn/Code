#include<bits/stdc++.h>
using namespace std;
const int N=1010;
struct node{
    int l,r,size,rnd,v;
}t[N<<5];
int n,m,T,cnt=1,rt[N],ans[N];
void update(int k){
    t[k].size=t[t[k].l].size+t[t[k].r].size+1;
}
void newnode(int &k,int x){
    t[k=++cnt].v=x;t[k].size=1;t[k].rnd=rand();
}
int merge(int a,int b){
    if(!a||!b)return a+b;
    if(t[a].rnd>t[b].rnd){
        int p=++cnt;t[p]=t[a];
        t[p].r=merge(t[p].r,b);
        update(p);return p;
    }else{
        int p=++cnt;t[p]=t[b];
        t[p].l=merge(a,t[p].l);
        update(p);return p;
    }
}
void split(int now,int k,int &x,int &y){
    if(!now)x=y=0;
    else{
        if(t[now].v<=k){
            x=++cnt;t[x]=t[now];
            split(t[x].r,k,t[x].r,y);
            update(x);
        }else{
            y=++cnt;t[y]=t[now];
            split(t[y].l,k,x,t[y].l);
            update(y);
        }
    }
}
void del(int &root,int k){
    int x=0,y=0,z=0;
    split(root,k,x,z);
    split(x,k-1,x,y);
    y=merge(t[y].l,t[y].r);
    root=merge(merge(x,y),z);
}
void ins(int &root,int k){
    int x=0,y=0,z=0;
    split(root,k,x,y);
    newnode(z,k);
    root=merge(merge(x,z),y);
}
int rnk(int x,int k){
    if(k==t[t[x].l].size+1)return t[x].v;
    else if(k<=t[t[x].l].size)return rnk(t[x].l,k);
    else return rnk(t[x].r,k-t[t[x].l].size-1);
}
int kth(int &root,int k){
    int x,y;
    split(root,k-1,x,y);
    int ans=t[x].size+1;
    root=merge(x,y);
    return ans;
}
int pre(int &root,int k){
    int x,y,k,ans;
    split(root,k-1,x,y);
    if(!x)return -1;
    k=t[x].size;
    ans=rnk(x,k);
    root=merge(x,y);
    return ans;
}
int main(){
    scanf("%d%d%d",&n,&m,&T);
    for(int i=1;i<=n;++i){
        int t,q,k;
        scanf("%d%d%d",&t,&q,&k);
        rt[i]=rt[t];
        if(q==1)ins(rt[i],k);
        else if(q==2)del(rt[i],k);
    }
    for(int i=1;i<=m;i++){
        int t,q,k,b,c;
        scanf("%d%d%d%d",&q,&k,&b,&c);
        rt[i]=rt[t];
        t=((b*ans[i-1]+c)%T+T)%T;
        if(q==3)ans[i]=kth(rt[i],k);
        else ans[i]=pre(rt[i],k);
        cout<<ans[i]<<endl;
    }
    return 0;
}