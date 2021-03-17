#include<bits/stdc++.h>
using namespace std;
const int N=100010*2;
int n,m;
int c[N],l[N],r[N],rt[N],d[N]={-1},tot;
int merge(int x,int y){
    if(!x||!y)return x+y;
    if(c[x]>c[y])swap(x,y);
    r[x]=merge(r[x],y);
    if(d[l[x]]<d[r[x]]){
        swap(l[x],r[x]);
    }
    d[x]=d[r[x]]+1;
    return x;
}
void insert(int &x,int k){
    tot++;
    c[tot]=k;
    l[tot]=r[tot]=0;
    x=merge(x,tot);
}
int main(){
    cin>>n>>m;
    tot=n;
    for(int i=1;i<=n;i++){
        c[i]=i;
        rt[i]=i;
    }
    for(int i=1;i<=m;i++){
        /* 
        op1则再输入两个数x，y，表示将第y个集合合并至第x个集合，第y个集合变为空集。
        op2，则再输入一个数x，表示询问第x个集合中的数的最小值，若第x个集合为空集输出-1。
        op3，则再输入两个数x，y，表示向第x个集合中插入一个数y。集合中的数允许重复。
        op4，则再输入一个数x，表示删除第x个集合中的最小的数，若第x个集合为空集则不操作。如果有多个最小值，只删除一个。
        */
        int op,x,y;
        cin>>op>>x;
        if(op==1){
            cin>>y;
            rt[x]=merge(rt[x],rt[y]);
            rt[y]=0;
        }else if(op==2){
            if(!rt[x])cout<<-1<<endl;
            else cout<<c[rt[x]]<<endl;
        }else if(op==3){
            cin>>y;
            insert(rt[x],y);
        }else{
            if(rt[x]){
                if(!l[rt[x]]&&!r[rt[x]])rt[x]=0;
                else rt[x]=merge(l[rt[x]],r[rt[x]]);
            }
        }
    }
    return 0;
}