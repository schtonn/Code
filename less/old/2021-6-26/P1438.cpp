#include "iostream"
using namespace std;
const int N=1000010;
#define ls id<<1
#define rs id<<1|1
int a,s[N],n,m;
struct node{
    int l,r,sum,lazy;
}t[4*N];
void update(int id){
    t[id].sum=t[ls].sum+t[ls].lazy*(t[ls].r-t[ls].l+1)+
    t[rs].sum+t[rs].lazy*(t[rs].r-t[rs].l+1);
}
void pushdown(int id){
    if(t[id].lazy){
        t[ls].lazy+=t[id].lazy;
        t[rs].lazy+=t[id].lazy;
        t[id].sum+=t[id].lazy*(t[id].r-t[id].l+1);
        t[id].lazy=0;
    }
}
void buildtree(int id,int l,int r){
    t[id].l=l;
    t[id].r=r;
    t[id].lazy=0;
    if(l==r){
        t[id].sum=s[l];
        return;
    }
    int mid=(l+r)>>1;
    buildtree(ls,l,mid);
    buildtree(rs,mid+1,r);
    update(id);
}
void change(int id,int l,int r,int c){
    if(t[id].l>=l&&t[id].r<=r){
        t[id].lazy+=c;
        return;
    }
    pushdown(id);
    if(t[ls].r>=r)change(ls,l,r,c);
    else if(t[rs].l<=l)change(rs,l,r,c);
    else{
        change(ls,l,t[ls].r,c);
        change(rs,t[rs].l,r,c);
    }
    update(id);
}
int query(int id,int l,int r){
    if(t[id].l>=l&&t[id].r<=r){
        return t[id].sum+t[id].lazy*(t[id].r-t[id].l+1);
    }
    pushdown(id);
    if(t[ls].r>=r)return query(ls,l,r);
    else if(t[rs].l<=l)return query(rs,l,r);
    else{
        return query(ls,l,t[ls].r)+query(rs,t[rs].l,r);
    }
    update(id);
}
int main(){
    cin>>n>>m;
    int g=0;
    for(int i=1;i<=n;i++){
        cin>>a;
        s[i]=a-g;
        g=a;
    }
    buildtree(1,1,n);
    for(int i=1;i<=m;i++){
        int op,l,r,k,d,p;
        cin>>op;
        if(op==1){
            cin>>l>>r>>k>>d;
            change(1,l,l,k);
            if(l+1<=n&&l<r)change(1,l+1,r,d);
            if(r+1<=n)change(1,r+1,r+1,-(k+d*(r-l)));
        }
        else{
            cin>>p;
            cout<<query(1,1,p)<<endl;
        }
    }
    return 0;
}
/*
5 2
1 2 3 4 5
1 2 4 1 2
2 3
*/