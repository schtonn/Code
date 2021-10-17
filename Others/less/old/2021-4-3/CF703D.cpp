#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,m;
int a[N],ans[N],sum[N];
map<int,int>pos;
struct Query{
    int L,R,id;
    bool operator<(const Query&b)const{
        return R<b.R;
    }
}q[N];
int lowbit(int x){
    return x&-x;
}
struct BIT{
    int c[N];
    void change(int x,int y){
        while(x<=n){
            c[x]^=y;
            x+=lowbit(x);
        }
    }
    int query(int x){
        int ret=0;
        while(x){
            ret^=c[x];
            x-=lowbit(x);
        }
        return ret;
    }
}t;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i];
    scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d%d",&q[i].L,&q[i].R),q[i].id=i;
    sort(q+1,q+m+1);
    int p=0;
    for(int i=1;i<=m;i++){
        while(p<q[i].R){
            p++;
            t.change(p,a[p]);
            if(pos.find(a[p])!=pos.end()){
                t.change(pos[a[p]],a[p]);
            }
            pos[a[p]]=p;
        }
        ans[q[i].id]=t.query(q[i].R)^t.query(q[i].L-1)^sum[q[i].R]^sum[q[i].L-1];
    }
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}